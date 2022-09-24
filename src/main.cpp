#include "mainwindow.h"
#include "myDebug.h"

#include <QApplication>

#include "opencv2/opencv.hpp"
#include "Eigen/Dense"

using namespace cv;
using namespace std;

Mat convertTo3Channels(const Mat& binImg)
{
    Mat three_channel = Mat::zeros(binImg.rows, binImg.cols, CV_8UC3);
    vector<Mat> channels;
    for (int i = 0; i < 3; i++)
    {
        channels.push_back(binImg);
    }
    merge(channels, three_channel);
    return three_channel;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


    //Mat src = imread("./cam0.png", 0);
    //if (src.data == Q_NULLPTR) {
    //    return -1;
    //}
    //imshow("src", src);
    //waitKey();
    //QImage srcQI = ImageHandle::Mat2QImage(src);
    //Mat srcConvert = ImageHandle::QImage2Mat(srcQI);
    //imshow("convert", srcConvert);
    //waitKey();
    //Mat result = convertTo3Channels(src);
    //imshow("111", result);
    //waitKey();
    system("pause");
    return 0;

}
 