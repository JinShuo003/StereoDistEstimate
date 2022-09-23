#include "myDebug.h"

#include "fstream"

using namespace Eigen;

void myDebug::CamParaDebug(singleCamPara* pSingleCamPara)
{
    using std::cout;
    using std::endl;

    cout << "TBC: " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << pSingleCamPara->extrinsicTBC.at<float>(i, j) << '\t';
        }
        cout << endl;
    }
    cout << endl;

    cout << "nRate: " << pSingleCamPara->nRate << endl;
    cout << endl;

    cout << "vResolution: ";
    for (int i = 0; i < pSingleCamPara->vResolution.size(); i++)
    {
        if (i != pSingleCamPara->vResolution.size() - 1)
            cout << pSingleCamPara->vResolution[i] << ',';
        else
            cout << pSingleCamPara->vResolution[i];
    }
    cout << endl;
    cout << endl;

    cout << "sCameraModel: " << pSingleCamPara->sCameraModel << endl;
    cout << endl;

    cout << "intrinsic: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << pSingleCamPara->intrinsic.at<float>(i, j) << '\t';
        }
        cout << endl;
    }
    cout << endl;

    cout << "sDistortionModel: " << pSingleCamPara->sDistortionModel << endl;
    cout << endl;

    cout << "vDistortion: ";
    for (int i = 0; i < 4; i++)
    {
            cout << pSingleCamPara->distortionCoefficient.at<float>(0, i) << '\t';
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

void myDebug::CvMatDebug(cv::Mat CvMat, qint8 mode, QString outputFilePath)
{
    if (mode == m_outputMode::file) {
        ofstream of(outputFilePath.toStdString());//输出cout信息的文件
        streambuf* fileBuf = of.rdbuf();// 获取文件out.txt流缓冲区指针
        std::cout.rdbuf(fileBuf);// 设置cout流缓冲区指针为out.txt的流缓冲区指针
        std::cout << "hello world!" << std::endl;
    }
    for (int i = 0; i < CvMat.rows; i++)
    {
        for (int j = 0; j < CvMat.cols; j++)
        {
            std::cout << CvMat.at<double>(i, j) << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void myDebug::EigenTest()
{
    Isometry3d T = Isometry3d::Identity();

    Matrix3d rotationMat;

    rotationMat <<
        0.0126, -0.9998, 0.0182,
        0.9996, 0.0130, 0.0252,
        -0.0254, 0.0179, 0.9995;

    Quaternion<double> quaternion(rotationMat);
    cout << quaternion << endl;

    Vector3d translationVec;
    translationVec << -0.0198, 0.0454, 0.0079;

    T.rotate(rotationMat);
    T.pretranslate(translationVec);

    
}

