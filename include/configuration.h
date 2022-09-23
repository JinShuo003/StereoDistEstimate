#pragma once

#include <QMainWindow>

#include "ui_configuration.h"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "yaml-cpp/yaml.h"
#include "Eigen/Dense"
#include "myMath.h"

typedef struct singleCamPara {
    //外参矩阵
    cv::Mat extrinsicTBC = cv::Mat::zeros(4, 4, CV_64F);
    //采样频率
    int nRate = 0;
    //分辨率
    std::vector<int> vResolution;
    //相机模型
    std::string sCameraModel;
    //内参矩阵
    cv::Mat intrinsic = cv::Mat::zeros(3, 3, CV_64F);
    //畸变模型
    std::string sDistortionModel;
    //畸变系数
    cv::Mat distortionCoefficient = cv::Mat::zeros(4, 1, CV_64F);
    //修正矩阵，实际位姿到校正后位姿的变换
    cv::Mat correctionR = cv::Mat::zeros(3, 3, CV_64F);
    //投影矩阵，将三维点直接投影到像素坐标系下
    cv::Mat projectionMatrix = cv::Mat::zeros(3, 3, CV_64F);
}singleCamPara;

typedef struct cameraPara {
    //cam0参数
    singleCamPara *cam0Para = Q_NULLPTR;
    //cam1参数
    singleCamPara *cam1Para = Q_NULLPTR;
    //cam1到cam0的变换矩阵
    cv::Mat extrinsicT10 = cv::Mat::zeros(4, 4, CV_64F);
    //Q矩阵，视差图到深度图的转换
    cv::Mat Q = cv::Mat::zeros(3, 3, CV_64F);
}cameraPara;

typedef struct yamlPara {
    std::vector<float> extrinsicTBC;
    int nRate;
    std::vector<int> vResolution;
    std::string sCameraModel;
    std::vector<float> intrinsic;
    std::string sDistortionModel;
    std::vector<float> vDistortion;
}yamlPara;

typedef struct singleCamShowPara {
    QString sExtrinsicTBC;
    QString sRate;
    QString sResolution;
    QString sCameraModel;
    QString sFu;
    QString sFv;
    QString sCu;
    QString sCv;
    QString sDistortionModel;
    QString sDistortion;
    QString sCorrectionR;
    QString sProjectionMatrix;
}singleCamShowPara;

typedef struct showPara {
    singleCamShowPara* cam0ShowPara = Q_NULLPTR;
    singleCamShowPara* cam1ShowPara = Q_NULLPTR;
    QString sT10;
    QString sQ;
}showPara;

class configuration : public QMainWindow
{
    Q_OBJECT
public:
	configuration(QWidget* parent = nullptr);
	~configuration();
    static void GetCamParaFromYaml(yamlPara yamlData, singleCamPara& camData);
    static bool GetShowParaFromYaml(yamlPara yamlData, singleCamShowPara& showData);
    static bool GetCamParaFromShow(singleCamShowPara showData, singleCamPara& camData);
    static void GetCalibShowParaFromCam(cameraPara camData, showPara& showData);
    static void ConvertMatToString(cv::Mat mat, QString& str);

private:
    void Init();
    //正则检查数据合法性
    bool CheckShowDataExp(singleCamShowPara showData);
public:
	cameraPara* m_pCameraPara = Q_NULLPTR;
    showPara* m_pShowPara = Q_NULLPTR;

private :
	Ui::configurationClass ui;
    bool bCam0Saved = false;
    bool bCam1Saved = false;

signals:
    void ParaAccepted(bool success);

private slots:
    void Slot_ConfirmBtn_clicked();
    void Slot_LoadFromFileBtn_clicked();
};
