#pragma once

#include <QMainWindow>

#include "ui_configuration.h"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "yaml-cpp/yaml.h"
#include "Eigen/Dense"
#include "myMath.h"

typedef struct singleCamPara {
    //��ξ���
    cv::Mat extrinsicTBC = cv::Mat::zeros(4, 4, CV_64F);
    //����Ƶ��
    int nRate = 0;
    //�ֱ���
    std::vector<int> vResolution;
    //���ģ��
    std::string sCameraModel;
    //�ڲξ���
    cv::Mat intrinsic = cv::Mat::zeros(3, 3, CV_64F);
    //����ģ��
    std::string sDistortionModel;
    //����ϵ��
    cv::Mat distortionCoefficient = cv::Mat::zeros(4, 1, CV_64F);
    //��������ʵ��λ�˵�У����λ�˵ı任
    cv::Mat correctionR = cv::Mat::zeros(3, 3, CV_64F);
    //ͶӰ���󣬽���ά��ֱ��ͶӰ����������ϵ��
    cv::Mat projectionMatrix = cv::Mat::zeros(3, 3, CV_64F);
}singleCamPara;

typedef struct cameraPara {
    //cam0����
    singleCamPara *cam0Para = Q_NULLPTR;
    //cam1����
    singleCamPara *cam1Para = Q_NULLPTR;
    //cam1��cam0�ı任����
    cv::Mat extrinsicT10 = cv::Mat::zeros(4, 4, CV_64F);
    //Q�����Ӳ�ͼ�����ͼ��ת��
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
    //���������ݺϷ���
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
