#include "imageHandle.h"

#include "QMessageBox"
#include "QDebug"

ImageHandle::ImageHandle()
{

}

QImage ImageHandle::Mat2QImage(const cv::Mat& mat)
{
    const unsigned char* data = mat.data;

    int width = mat.cols;
    int height = mat.rows;
    int bytesPerLine = static_cast<int>(mat.step);
    switch(mat.type())
    {
        //8 bit ARGB
        case CV_8UC4:
        {
            QImage image(data, width, height, bytesPerLine, QImage::Format_ARGB32);
            return image;
        }
        //8 bit BGR
        case CV_8UC3:
        {
            QImage image(data, width, height, bytesPerLine, QImage::Format_RGB888);
            //swap blue and red channel
            return image.rgbSwapped();
        }
        //8 bit Gray shale
        case CV_8UC1:
        {
            //QImage image(data, width, height, bytesPerLine, QImage::Format_Grayscale8);
            //return image;
            QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
            //转换为qimage 单通道颜色值
            image.setColorCount(256);
            for (int i = 0; i < 256; i++)
            {
                image.setColor(i, qRgb(i, i, i));
            }
            uchar* pSrc = mat.data;
            for (int row = 0; row < mat.rows; row++)
            {
                uchar* pDest = image.scanLine(row);
                memcpy(pDest, pSrc, mat.cols);
                pSrc += mat.step;
            }
            return image;
        }
        //unsopport type
        default:
        {
            QMessageBox::critical(Q_NULLPTR, "Error", "Unsopported image type");
            return QImage();
        }
    }
}


cv::Mat ImageHandle::QImage2Mat(QImage image)
{
    cv::Mat mat;   //创建一个mat对象来接收
    switch (image.format())  //QImage 的一个库函数 可以返回图片的类型
    {
    case QImage::Format_ARGB32_Premultiplied:  //RGB32 为四通道的所以在调用mat构造函数需要转换成四通道的mat类型（CV_8UC4）
        mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
        break;
    case QImage::Format_RGB888:   //RGB888 即RGB24 三通道八位的图片 所以转成三通道的mat(CV_8UC3)
        mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
        //因为Qimage 是RGB 通道 而 Mat 为 BGR 通道 所以需要使用cvtcolor进行转换，不然图片通道会颠倒
        cv::cvtColor(mat, mat, cv::COLOR_RGB2BGR);
        break;
    case QImage::Format_Indexed8:  //Indexed8 为单通道的图片 所以在转换成mat 也是单通道（CV_8UC1）
        mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
        break;
    case QImage::Format_Grayscale8:
        mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
        break;
    default:
        QMessageBox::critical(Q_NULLPTR, "Error", "Unsopported image type");
        break;
    }
    return mat;
}

