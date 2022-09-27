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
    //界面
    Ui::MainWindow* ui = Q_NULLPTR;
    //配置信息窗口
    configuration* m_pConigWindow = Q_NULLPTR;
    //OPENGL窗口
    OpenGLWidget* m_pOpenGLWidget = Q_NULLPTR;
    //可执行文件目录
    const QString m_sExePath = QCoreApplication::applicationDirPath();
    //原图
    QImage m_imgLeft;
    QImage m_imgRight;
    //校正图
    QImage m_rectifyImgLeft;
    QImage m_rectifyImgRight;
    //特征匹配图
    QImage m_featureMatchImg;
    //视差图
    QImage m_disparityImg;
    //图像特征信息，包括特征点、描述子、匹配关系、视差、深度等
    stereoImgInfo imgFeatureInformation;

    /*-----------------------单张模式----------------------*/
    //左右图像是否已加载
    bool m_bIsLeftImgIsLoaded = false;
    bool m_bIsRightImgIsLoaded = false;
    //是否已成功加载配置
    bool m_bParaAccepted = false;
    //是否已经双目校正
    bool m_bIsStereoCalibrated = false;
    //是否已经特征提取
    bool m_bIsFeatureExtracted = false;
    //是否已经计算深度
    bool m_bIsDepthCalculated = false;
    //是否已经加载视差图
    bool m_bIsDisparityImgLoaded = false;
    //结果保存文件
    QFile* m_pResFile = Q_NULLPTR;

    /*-----------------------连续模式----------------------*/
    //左侧文件夹
    QDir m_sImgDirLeft;
    //右侧文件夹
    QDir m_sImgDirRight;
    //图像名，左右侧必须一一对应，若找不到对应则跳过
    QStringList m_ImgNameList;
    //图像名迭代器，指向当前处理完的图像
    QStringList::iterator m_itImgName;
    //左右文件夹是否已加载
    bool m_bLeftImgDirIsReady = false;
    bool m_bRightImgDirIsReady = false;
    //加载图像定时器
    QTimer* loadNextImgTimer = Q_NULLPTR;

public:
    //显示图片的区域
    enum m_showImageArea { left = 0, right = 1, disparity = 2, featureMatch = 3};
    Q_ENUM(m_showImageArea)
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    //初始化系统
    void InitSystem();
    //加载左右侧图像
    bool LoadImageFromPath(QString imgPath, qint8 area);
    //显示左右侧图像
    void ShowImage(QImage image, qint8 area);
    //显示立体校正结果
    void ShowCalibData();
    //ORB特征匹配
    void ORBfeatureMatch();
    //!!TODO,SURF特征匹配
    void SURFfeatureMatch();
    //单通道图片转三通道
    cv::Mat OneChannel2ThreeChannel(const cv::Mat& src);
    //处理当前图像
    void ProcessCurrentImg();
    //在左右两张图上绘制匹配的关键点和匹配关系
    cv::Mat DrawMatches(const cv::Mat& leftImg, const cv::Mat& rightImg, const std::vector<cv::KeyPoint>& vKeyPoints1,
        const std::vector<cv::KeyPoint>& vKeyPoints2, const std::vector<cv::DMatch>& vInputMatch, 
        const std::vector<cv::Scalar>& vColor);
    //在特征匹配图上的左侧图像特征点旁绘制深度
    cv::Mat DrawDepth(const cv::Mat& featureMatchImg, const std::vector<cv::KeyPoint>& vKeyPointsLeft, 
        const std::vector<cv::DMatch>& vInputMatch, const std::vector<cv::Point3d>& v3dPoints,
        const std::vector<cv::Scalar>& vColor);
    //在特征匹配图上的左侧图像特征点旁绘制深度及误差
    cv::Mat DrawDepthAndError(const cv::Mat& featureMatchImg, const std::vector<cv::KeyPoint>& vKeyPointsLeft,
        const std::vector<cv::DMatch>& vInputMatch, const std::vector<cv::Point3d>& v3dPoints,
        const std::vector<float>& vError, const std::vector<cv::Scalar>& vColor);
    //检查图像尺寸是否合法
    bool CheckImgSize();
    //检查是否满足条件进行立体校正
    bool CheckCalibEnable();
    //检查是否满足条件进行误差计算
    bool CheckCalErrorEnable();
    //检查是否满足条件进行连续处理
    bool CheckContinuousProcessEnable();
    //检查当前图片名迭代器指向的元素是否可以被正常处理
    bool CheckProcessNormal();
    //距离法特征点筛选
    std::vector<cv::DMatch> DisFilter(const std::vector<cv::DMatch>& vInputMatch);
    //余弦法特征点筛选
    std::vector<cv::DMatch> CosFilter(const std::vector<cv::DMatch>& vInputMatch,
        const cv::Mat& descriptors1, const cv::Mat& descriptors2);
    //平均距离法特征点筛选
    std::vector<cv::DMatch> AverDisFilter(const std::vector<cv::DMatch>& vInputMatch);
    //基于规则的特征点筛选
    std::vector<cv::DMatch> StereoRuleFilter(const std::vector<cv::KeyPoint>& vKeyPoints1,
        const std::vector<cv::KeyPoint>& vKeyPoints2, const std::vector<cv::DMatch>& vInputMatch);
    //基于特征点位置的特征点筛选，筛去距离过近的特征点
    std::vector<cv::DMatch> LocationFilter(const std::vector<cv::KeyPoint>& vKeyPoints1,
        const std::vector<cv::KeyPoint>& vKeyPoints2, const std::vector<cv::DMatch>& vInputMatch);
    //!!TODO,RANSAC方法特征点筛选
    std::vector<cv::DMatch> RansacFilter(const cv::Mat& imgLeft, const std::vector<cv::DMatch>& vInputMatch,
        const std::vector<cv::KeyPoint>& vKeyPointLeft, const std::vector<cv::KeyPoint>& vKeyPointRight);
    //鼠标点击，改变焦点
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
    void Slot_PauseBtn_clicked();
    void Slot_NextImg_clicked();
    void Slot_LastImg_clicked();
    void Slot_Reset_clicked();
    void Slot_ImgDirIsReady();
    void Slot_StopAutoMode();

public slots:
    void Slot_ParaAccepted(bool success);

};
