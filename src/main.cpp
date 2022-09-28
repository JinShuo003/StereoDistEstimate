#include "mainwindow.h"
#include "viewer/OpenGLWidget.h"
#include "myDebug.h"

#include <QApplication>

#include "opencv2/opencv.hpp"
#include "Eigen/Dense"

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //OpenGLWidget w;
    //w.setFixedSize(960, 540);
    w.show();
    return a.exec();
}
 