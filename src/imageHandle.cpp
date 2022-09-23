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
            //ת��Ϊqimage ��ͨ����ɫֵ
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
    cv::Mat mat;   //����һ��mat����������
    switch (image.format())  //QImage ��һ���⺯�� ���Է���ͼƬ������
    {
    case QImage::Format_ARGB32_Premultiplied:  //RGB32 Ϊ��ͨ���������ڵ���mat���캯����Ҫת������ͨ����mat���ͣ�CV_8UC4��
        mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
        break;
    case QImage::Format_RGB888:   //RGB888 ��RGB24 ��ͨ����λ��ͼƬ ����ת����ͨ����mat(CV_8UC3)
        mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
        //��ΪQimage ��RGB ͨ�� �� Mat Ϊ BGR ͨ�� ������Ҫʹ��cvtcolor����ת������ȻͼƬͨ����ߵ�
        cv::cvtColor(mat, mat, cv::COLOR_RGB2BGR);
        break;
    case QImage::Format_Indexed8:  //Indexed8 Ϊ��ͨ����ͼƬ ������ת����mat Ҳ�ǵ�ͨ����CV_8UC1��
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

