#ifndef QCVMATDATACORVENT_H
#define QCVMATDATACORVENT_H

#include "QImage"

#include "opencv2/opencv.hpp"


class ImageHandle
{
public:
    ImageHandle();

    static QImage Mat2QImage(const cv::Mat& mat);
    static cv::Mat QImage2Mat(QImage image);

};

#endif // QCVMATDATACORVENT_H
