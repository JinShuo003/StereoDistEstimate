#pragma once

#include "imageHandle.h"
#include "configuration.h"
#include "viewer/OpenGLWidget.h"

#include "vector"

#include <QMainWindow>
#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QTimer>

typedef struct {
    std::vector<cv::KeyPoint> vKeyPoints1;
    std::vector<cv::KeyPoint> vKeyPoints2;
    cv::Mat descriptors1;
    cv::Mat descriptors2;
    std::vector<cv::DMatch> matches;
    std::vector<int> vParallax;
    std::vector<float> vError;
    std::vector<cv::Point3d> v3dPoints;
    std::vector<cv::Scalar> vColor;
}stereoImgInfo;

namespace Ui {
class MainWindow;
}

class MainWindow: public QMainWindow
{
    Q_OBJECT
private:
    //����
    Ui::MainWindow* ui = Q_NULLPTR;
    //������Ϣ����
    configuration* m_pConigWindow = Q_NULLPTR;
    //OPENGL����
    OpenGLWidget* m_pOpenGLWidget = Q_NULLPTR;
    //��ִ���ļ�Ŀ¼
    const QString m_sExePath = QCoreApplication::applicationDirPath();
    //ԭͼ
    QImage m_imgLeft;
    QImage m_imgRight;
    //У��ͼ
    QImage m_rectifyImgLeft;
    QImage m_rectifyImgRight;
    //����ƥ��ͼ
    QImage m_featureMatchImg;
    //�Ӳ�ͼ
    QImage m_disparityImg;
    //ͼ��������Ϣ�����������㡢�����ӡ�ƥ���ϵ���Ӳ��ȵ�
    stereoImgInfo imgFeatureInformation;

    /*-----------------------����ģʽ----------------------*/
    //����ͼ���Ƿ��Ѽ���
    bool m_bIsLeftImgIsLoaded = false;
    bool m_bIsRightImgIsLoaded = false;
    //�Ƿ��ѳɹ���������
    bool m_bParaAccepted = false;
    //�Ƿ��Ѿ�˫ĿУ��
    bool m_bIsStereoCalibrated = false;
    //�Ƿ��Ѿ�������ȡ
    bool m_bIsFeatureExtracted = false;
    //�Ƿ��Ѿ��������
    bool m_bIsDepthCalculated = false;
    //�Ƿ��Ѿ������Ӳ�ͼ
    bool m_bIsDisparityImgLoaded = false;
    //��������ļ�
    QFile* m_pResFile = Q_NULLPTR;

    /*-----------------------����ģʽ----------------------*/
    //����ļ���
    QDir m_sImgDirLeft;
    //�Ҳ��ļ���
    QDir m_sImgDirRight;
    //ͼ���������Ҳ����һһ��Ӧ�����Ҳ�����Ӧ������
    QStringList m_ImgNameList;
    QStringList::iterator m_itImgName;
    //�����ļ����Ƿ��Ѽ���
    bool m_bLeftImgDirIsReady = false;
    bool m_bRightImgDirIsReady = false;
    //����ͼ��ʱ��
    QTimer* loadNextImgTimer = Q_NULLPTR;

public:
    //��ʾͼƬ������
    enum m_showImageArea { left = 0, right = 1, disparity = 2, featureMatch = 3};
    Q_ENUM(m_showImageArea)
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    //��ʼ��ϵͳ
    void InitSystem();
    //�������Ҳ�ͼ��
    bool LoadImageFromPath(QString imgPath, qint8 area);
    //��ʾ���Ҳ�ͼ��
    void ShowImage(QImage image, qint8 area);
    //��ʾ����У�����
    void ShowCalibData();
    //ORB����ƥ��
    void ORBfeatureMatch();
    //!!TODO,SURF����ƥ��
    void SURFfeatureMatch();
    //��ͨ��ͼƬת��ͨ��
    cv::Mat OneChannel2ThreeChannel(const cv::Mat& src);
    //����������ͼ�ϻ���ƥ��Ĺؼ����ƥ���ϵ
    cv::Mat DrawMatches(const cv::Mat& leftImg, const cv::Mat& rightImg, std::vector<cv::KeyPoint> vKeyPoints1,
        std::vector<cv::KeyPoint> vKeyPoints2, std::vector<cv::DMatch> vInputMatch, std::vector<cv::Scalar> vColor);
    //������ƥ��ͼ�ϵ����ͼ���������Ի������
    cv::Mat DrawDepth(const cv::Mat& featureMatchImg, std::vector<cv::KeyPoint> vKeyPointsLeft, std::vector<cv::DMatch> vInputMatch,
        std::vector<cv::Point3d> v3dPoints, std::vector<cv::Scalar> vColor);
    //������ƥ��ͼ�ϵ����ͼ���������Ի�����ȼ����
    cv::Mat DrawDepthAndError(const cv::Mat& featureMatchImg, std::vector<cv::KeyPoint> vKeyPointsLeft, std::vector<cv::DMatch> vInputMatch,
        std::vector<cv::Point3d> v3dPoints, std::vector<float> vError, std::vector<cv::Scalar> vColor);
    //���ͼ��ߴ��Ƿ�Ϸ�
    bool CheckImgSize();
    //����Ƿ�����������������У��
    bool CheckCalibEnable();
    //����Ƿ�������������������
    bool CheckCalErrorEnable();
    //����Ƿ���������������������
    bool CheckContinuousProcessEnable();
    //���뷨������ɸѡ
    std::vector<cv::DMatch> DisFilter(std::vector<cv::DMatch> vInputMatch);
    //���ҷ�������ɸѡ
    std::vector<cv::DMatch> CosFilter(std::vector<cv::DMatch> vInputMatch,
        cv::Mat descriptors1, cv::Mat descriptors2);
    //ƽ�����뷨������ɸѡ
    std::vector<cv::DMatch> AverDisFilter(std::vector<cv::DMatch> vInputMatch);
    //���ڹ����������ɸѡ
    std::vector<cv::DMatch> StereoRuleFilter(std::vector<cv::KeyPoint> vKeyPoints1,
        std::vector<cv::KeyPoint> vKeyPoints2, std::vector<cv::DMatch> vInputMatch);
    //����������λ�õ�������ɸѡ��ɸȥ���������������
    std::vector<cv::DMatch> LocationFilter(std::vector<cv::KeyPoint> vKeyPoints1,
        std::vector<cv::KeyPoint> vKeyPoints2, std::vector<cv::DMatch> vInputMatch);
    //!!TODO,RANSAC����������ɸѡ
    std::vector<cv::DMatch> RansacFilter(cv::Mat imgLeft, std::vector<cv::DMatch> vInputMatch,
        std::vector<cv::KeyPoint> vKeyPointLeft, std::vector<cv::KeyPoint> vKeyPointRight);
    //��������ı佹��
    void mousePressEvent(QMouseEvent* event);

signals:
    void Signal_ImgDirIsReady();
    void Signal_StopAutoMode();

private slots:
    void Slot_OpenImgBtn_clicked();
    bool Slot_StereoCalibBtn_clicked();
    bool Slot_ExtractFeaturesBtn_clicked();
    bool Slot_CalDepthBtn_clicked();
    void Slot_SaveDataBtn_clicked();
    void Slot_LoadDisparityBtn_clicked();
    void Slot_CalErrorBtn_clicked();
    void Slot_ModifyParaBtn_clicked();
    void Slot_OpenDirBtn_clicked();
    void Slot_AutoStartBtn_clicked();
    void Slot_ProcessNextImg();
    void Slot_PauseBtn_clicked();
    void Slot_NextImg_clicked();
    void Slot_Reset_clicked();
    void Slot_ImgDirIsReady();
    void Slot_StopAutoMode();

public slots:
    void Slot_ParaAccepted(bool success);

};
