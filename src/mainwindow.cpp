#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myDebug.h"
#include "myMath.h"

#include "opencv2/opencv.hpp"

#include "QDebug"
#include "QFileDialog"
#include "QPushButton"
#include "QMessageBox"
#include "QTextStream"
#include "QJsonArray"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonValue"
#include "QRandomGenerator"

#include <iostream>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitSystem();
}

MainWindow::~MainWindow()
{
    if (Q_NULLPTR != ui) {
        delete ui;
    }
    if (Q_NULLPTR != m_pConigWindow) {
        delete m_pConigWindow;
    }
    if (Q_NULLPTR != m_pOpenGLWidget) {
        delete m_pOpenGLWidget;
    }
    if (Q_NULLPTR != m_pResFile) {
        delete m_pResFile;
    }
}

void MainWindow::InitSystem(){
    //实例化
    if (Q_NULLPTR == m_pConigWindow) {
        m_pConigWindow = new configuration(this);
    }
    if (Q_NULLPTR == loadNextImgTimer) {
        loadNextImgTimer = new QTimer(this);
    }

    //调整样式
    this->setFixedSize(this->size());
    ui->label_ImgName->setStyleSheet("color:red;");

    //信号连接
    connect(ui->btn_OpenLeftImg, &QPushButton::clicked, this, &MainWindow::Slot_OpenImgBtn_clicked);
    connect(ui->btn_OpenRightImg, &QPushButton::clicked, this, &MainWindow::Slot_OpenImgBtn_clicked);
    connect(ui->btn_ModifyPara, &QPushButton::clicked, this, &MainWindow::Slot_ModifyParaBtn_clicked);
    connect(ui->btn_StereoCalib, &QPushButton::clicked, this, &MainWindow::Slot_StereoCalibBtn_clicked);
    connect(ui->btn_ExtractFeatures, &QPushButton::clicked, this, &MainWindow::Slot_ExtractFeaturesBtn_clicked);
    connect(ui->btn_CalDepth, &QPushButton::clicked, this, &MainWindow::Slot_CalDepthBtn_clicked);
    connect(ui->btn_SaveData, &QPushButton::clicked, this, &MainWindow::Slot_SaveDataBtn_clicked);
    connect(ui->btn_LoadDisparity, &QPushButton::clicked, this, &MainWindow::Slot_LoadDisparityBtn_clicked);
    connect(ui->btn_CalError, &QPushButton::clicked, this, &MainWindow::Slot_CalErrorBtn_clicked);
    connect(ui->btn_SelectDirLeft, &QPushButton::clicked, this, &MainWindow::Slot_OpenDirBtn_clicked);
    connect(ui->btn_SelectDirRight, &QPushButton::clicked, this, &MainWindow::Slot_OpenDirBtn_clicked);
    connect(ui->btn_AutoStart, &QPushButton::clicked, this, &MainWindow::Slot_AutoStartBtn_clicked);
    connect(ui->btn_Pause, &QPushButton::clicked, this, &MainWindow::Slot_PauseBtn_clicked);
    connect(ui->btn_NextImg, &QPushButton::clicked, this, &MainWindow::Slot_NextImg_clicked);
    connect(ui->btn_Reset, &QPushButton::clicked, this, &MainWindow::Slot_Reset_clicked);

    connect(this, &MainWindow::Signal_ImgDirIsReady, this, &MainWindow::Slot_ImgDirIsReady);
    connect(this, &MainWindow::Signal_StopAutoMode, this, &MainWindow::Slot_StopAutoMode);
    connect(this->loadNextImgTimer, &QTimer::timeout, this, &MainWindow::Slot_ProcessNextImg);

    connect(m_pConigWindow, &configuration::ParaAccepted, this, &MainWindow::Slot_ParaAccepted);

}


void MainWindow::ShowImage(QImage image, qint8 area)
{
    //将显示图像resize为960*540
    QImage imgShow = QImage();
    imgShow = image.copy();
    if (area != m_showImageArea::featureMatch) {
        if (imgShow.size() != QSize(960, 540)) {
            imgShow = imgShow.scaled(QSize(960, 540));
        }
    }
    else {
        if (imgShow.size() != QSize(1920, 540)) {
            imgShow = imgShow.scaled(QSize(1920, 540));
        }
    }
    //根据传入的区域将图像显示在不同区域
    switch (area)
    {
    case m_showImageArea::left:
        ui->ImgLabelFeatureMatch->hide();
        ui->ImgLabelLeft->show();
        ui->ImgLabelLeft->setPixmap(QPixmap::fromImage(imgShow));
        break;
    case m_showImageArea::right:
        ui->ImgLabelFeatureMatch->hide();
        ui->ImgLabelRight->show();
        ui->ImgLabelRight->setPixmap(QPixmap::fromImage(imgShow));
        break;
    case m_showImageArea::disparity:
        ui->ImgLabelDisparity->show();
        ui->ImgLabelDisparity->setPixmap(QPixmap::fromImage(imgShow));
        break;
    case m_showImageArea::featureMatch:
        ui->ImgLabelLeft->hide();
        ui->ImgLabelRight->hide();
        ui->ImgLabelFeatureMatch->show();
        ui->ImgLabelFeatureMatch->setPixmap(QPixmap::fromImage(imgShow));
    default:
        break;
    }
}

bool MainWindow::LoadImageFromPath(QString imgPath, qint8 area)
{
    //从路径读取图像，若为空则返回false
    cv::Mat imgMat = cv::imread(imgPath.toStdString().c_str(), cv::IMREAD_GRAYSCALE);
    if (Q_NULLPTR == imgMat.data) {
        return false;
    }

    switch (area)
    {
    case m_showImageArea::left:
        m_imgLeft = ImageHandle::Mat2QImage(imgMat);
        m_bIsLeftImgIsLoaded = true;
        break;
    case m_showImageArea::right:
        m_imgRight = ImageHandle::Mat2QImage(imgMat);
        m_bIsRightImgIsLoaded = true;
        break;
    case m_showImageArea::disparity:
        m_disparityImg = ImageHandle::Mat2QImage(imgMat);
        //若视差图大小与原图不一致
        std::cout << QString("%1, %2").arg(m_disparityImg.width()).arg(m_disparityImg.height()).toStdString() << std::endl;
        std::cout << QString("%1, %2").arg(m_imgLeft.width()).arg(m_imgLeft.height()).toStdString() << std::endl;
        std::cout << QString("%1, %2").arg(m_imgRight.width()).arg(m_imgRight.height()).toStdString() << std::endl;
        if (m_disparityImg.size() != m_imgLeft.size() || m_disparityImg.size() != m_imgRight.size()) {
            m_bIsDisparityImgLoaded = false;
            return false;
        }
        m_disparityImg = ImageHandle::Mat2QImage(imgMat);
        m_bIsDisparityImgLoaded = true;
        break;
    default:
        break;
    }
    return true;
}

void MainWindow::ShowCalibData()
{
    ui->textEdit_RCor_cam0_show->setText(m_pConigWindow->m_pShowPara->cam0ShowPara->sCorrectionR);
    ui->textEdit_Proj_cam0_show->setText(m_pConigWindow->m_pShowPara->cam0ShowPara->sProjectionMatrix);
    ui->textEdit_RCor_cam1_show->setText(m_pConigWindow->m_pShowPara->cam1ShowPara->sCorrectionR);
    ui->textEdit_Proj_cam1_show->setText(m_pConigWindow->m_pShowPara->cam1ShowPara->sProjectionMatrix);
    ui->textEdit_T10_show->setText(m_pConigWindow->m_pShowPara->sT10);
    ui->textEdit_Q_show->setText(m_pConigWindow->m_pShowPara->sQ);
}

void MainWindow::ORBfeatureMatch()
{
    cv::Mat imgLeft = ImageHandle::QImage2Mat(m_rectifyImgLeft);
    cv::Mat imgRight = ImageHandle::QImage2Mat(m_rectifyImgRight);

    //特征点和描述子计算
    cv::Ptr<cv::ORB> ORBDetector = cv::ORB::create(500);
    ORBDetector->detectAndCompute(imgLeft, cv::Mat(), imgFeatureInformation.vKeyPoints1, imgFeatureInformation.descriptors1);
    std::cout << "kp1.size:" << imgFeatureInformation.vKeyPoints1.size() << std::endl;
    std::cout << "descriptors_1.size:" << imgFeatureInformation.descriptors1.size().height << std::endl;
    ORBDetector->detectAndCompute(imgRight, cv::Mat(), imgFeatureInformation.vKeyPoints2, imgFeatureInformation.descriptors2);
    std::cout << "kp2.size:" << imgFeatureInformation.vKeyPoints2.size() << std::endl;
    std::cout << "descriptors_2.size:" << imgFeatureInformation.descriptors2.size().height << std::endl;

    //特征匹配，暴力匹配
    cv::BFMatcher matcher(cv::NORM_HAMMING);
    std::vector<cv::DMatch> vMatches;
    matcher.match(imgFeatureInformation.descriptors1, imgFeatureInformation.descriptors2, vMatches);
    std::cout << "initial matches size:" << (int)vMatches.size() << std::endl;

    //匹配点筛选-距离筛选
    std::vector<cv::DMatch> distMatches;
    distMatches = DisFilter(vMatches);
    std::cout << "after distance filter matches size:" << (int)distMatches.size() << std::endl;

    //匹配点筛选-余弦筛选
    std::vector<cv::DMatch> angleMatches;
    angleMatches = CosFilter(distMatches, imgFeatureInformation.descriptors1, imgFeatureInformation.descriptors2);
    std::cout << "after cosine filter matches size:" << (int)angleMatches.size() << std::endl;

    //匹配点筛选-平均距离筛选
    std::vector<cv::DMatch> averDisMatches;
    averDisMatches = AverDisFilter(angleMatches);
    std::cout << "after average distance filter matches size:" << (int)averDisMatches.size() << std::endl;

    //规则筛选
    std::vector<cv::DMatch> ruleMatches;
    ruleMatches = StereoRuleFilter(imgFeatureInformation.vKeyPoints1, imgFeatureInformation.vKeyPoints2, averDisMatches);
    std::cout << "after rule filter matches size:" << (int)ruleMatches.size() << std::endl;

    //密度筛选
    std::vector<cv::DMatch> locationMatches;
    locationMatches = LocationFilter(imgFeatureInformation.vKeyPoints1, imgFeatureInformation.vKeyPoints2, ruleMatches);
    std::cout << "after location filter matches size:" << (int)locationMatches.size() << std::endl;
    //!!TODO 匹配点-RANSAC筛选
    //std::vector<cv::DMatch> RANSACMatches;
    //RANSACMatches = RansacFilter(imgLeft, angleMatches, kp1, kp2);
    //std::cout << "after RANSAC filter matches size:" << (int)RANSACMatches.size() << std::endl;

    imgFeatureInformation.matches = std::move(locationMatches);
}

void MainWindow::SURFfeatureMatch()
{
    
}

cv::Mat MainWindow::OneChannel2ThreeChannel(const cv::Mat& src)
{
    if (1 != src.channels()) {
        return cv::Mat();
    }
    cv::Mat _threeChannelImg = cv::Mat::zeros(src.rows, src.cols, CV_8UC3);
    std::vector<cv::Mat> _singleChannelImg;
    for (int i = 0; i < 3; i++)
    {
        _singleChannelImg.push_back(src);
    }
    cv::merge(_singleChannelImg, _threeChannelImg);
    return _threeChannelImg;
}

cv::Mat MainWindow::DrawMatches(const cv::Mat& leftImg, const cv::Mat& rightImg, const std::vector<cv::KeyPoint>& vKeyPoints1,
    const std::vector<cv::KeyPoint>& vKeyPoints2, const std::vector<cv::DMatch>& vInputMatch,
    const std::vector<cv::Scalar>& vColor)
{
    cv::Mat _leftImg = leftImg.clone();
    cv::Mat _rightImg = rightImg.clone();
    //处理图像通道
    if (_leftImg.channels() == 1) {
        _leftImg = OneChannel2ThreeChannel(_leftImg);
    }
    if (_rightImg.channels() == 1) {
        _rightImg = OneChannel2ThreeChannel(_rightImg);
    }
    //绘制特征点，并合并图像
    for (int i = 0; i < vInputMatch.size(); i++)
    {
        cv::Point keyPointLeft = vKeyPoints1[vInputMatch[i].queryIdx].pt;
        cv::Point keyPointRight = vKeyPoints2[vInputMatch[i].trainIdx].pt;
        cv::circle(_leftImg, keyPointLeft, 5, vColor[i], -1, cv::LINE_AA);
        cv::circle(_rightImg, keyPointRight, 5, vColor[i], -1, cv::LINE_AA);
    }
    int w1 = _leftImg.cols; int h1 = _leftImg.rows;
    int w2 = _rightImg.cols; int h2 = _rightImg.rows;
    int width = w1 + w2; int height = max(h1, h2);
    cv::Mat resultImg = cv::Mat(height, width, CV_8UC3, cv::Scalar::all(0));
    cv::Mat ROI_1 = resultImg(cv::Rect(0, 0, w1, h1));
    cv::Mat ROI_2 = resultImg(cv::Rect(w1, 0, w2, h2));
    _leftImg.copyTo(ROI_1);
    _rightImg.copyTo(ROI_2);
    //在合并后图像上绘制匹配关键点连线
    for (int i = 0; i < vInputMatch.size(); i++)
    {
        cv::Point keyPointLeft = vKeyPoints1[vInputMatch[i].queryIdx].pt;
        cv::Point keyPointRight = vKeyPoints2[vInputMatch[i].trainIdx].pt;
        cv::line(resultImg, keyPointLeft, cv::Point(keyPointRight.x + w1, keyPointRight.y),
            vColor[i], 3, cv::LINE_AA);
    }
    return resultImg;
}

cv::Mat MainWindow::DrawDepth(const cv::Mat& featureMatchImg, const std::vector<cv::KeyPoint>& vKeyPointsLeft,
    const std::vector<cv::DMatch>& vInputMatch, const std::vector<cv::Point3d>& v3dPoints,
    const std::vector<cv::Scalar>& vColor){
    cv::Mat _featureMatchImg = featureMatchImg.clone();
    //处理图像通道
    if (_featureMatchImg.channels() == 1) {
        _featureMatchImg = OneChannel2ThreeChannel(_featureMatchImg);
    }
    for (int i = 0; i < vInputMatch.size(); i++)
    {
        cv::Point2d left2dPoint = vKeyPointsLeft[vInputMatch[i].queryIdx].pt;
        cv::putText(_featureMatchImg, QString("%1").arg(QString::number(v3dPoints[i].z,
            'f', 2)).toStdString(), cv::Point(left2dPoint.x, left2dPoint.y - 5),
            cv::FONT_HERSHEY_TRIPLEX, 1.5, vColor[i], 2, cv::LINE_AA);
    }
    return _featureMatchImg;
}

cv::Mat MainWindow::DrawDepthAndError(const cv::Mat& featureMatchImg, const std::vector<cv::KeyPoint>& vKeyPointsLeft,
    const std::vector<cv::DMatch>& vInputMatch, const std::vector<cv::Point3d>& v3dPoints,
    const std::vector<float>& vError, const std::vector<cv::Scalar>& vColor)
{
    cv::Mat _featureMatchImg = featureMatchImg.clone();
    //处理图像通道
    if (_featureMatchImg.channels() == 1) {
        _featureMatchImg = OneChannel2ThreeChannel(_featureMatchImg);
    }
    for (int i = 0; i < vInputMatch.size(); i++)
    {
        cv::Point2d left2dPoint = vKeyPointsLeft[vInputMatch[i].queryIdx].pt;
        QString sText = QString("%1, %2\%").arg(QString::number(v3dPoints[i].z, 'f', 2))
            .arg(QString::number(vError[i] * 100.0, 'f', 2));
        cv::putText(_featureMatchImg, sText.toStdString(), cv::Point(left2dPoint.x, left2dPoint.y - 5),
            cv::FONT_HERSHEY_TRIPLEX, 1.5, vColor[i], 2, cv::LINE_AA);
    }
    return _featureMatchImg;
}

bool MainWindow::CheckImgSize()
{
    //左图与右图
    if (m_imgLeft.size() != m_imgRight.size()) {
        QMessageBox::warning(this, "Warning", "The resolution of the left and the right images not match");
        return false;
    }
    //左配置与右配置
    if (m_pConigWindow->m_pCameraPara->cam0Para->vResolution[0] != m_pConigWindow->m_pCameraPara->cam1Para->vResolution[0] || 
        m_pConigWindow->m_pCameraPara->cam0Para->vResolution[1] != m_pConigWindow->m_pCameraPara->cam1Para->vResolution[1]) {
        QMessageBox::warning(this, "Warning", "The resolution of the left and the right camera config files not match");
        return false;
    }
    //左图与左配置
    if (m_imgLeft.size().width() != m_pConigWindow->m_pCameraPara->cam0Para->vResolution[0] || 
        m_imgLeft.size().height() != m_pConigWindow->m_pCameraPara->cam0Para->vResolution[1]) {
        QMessageBox::warning(this, "Warning", "The resolution of the left image and the left camera config file not match");
        return false;
    }
    //右图与右配置
    if (m_imgRight.size().width() != m_pConigWindow->m_pCameraPara->cam1Para->vResolution[0] ||
        m_imgRight.size().height() != m_pConigWindow->m_pCameraPara->cam1Para->vResolution[1]) {
        QMessageBox::warning(this, "Warning", "The resolution of the right image and the right camera config file not match");
        return false;
    }
    return true;
}

bool MainWindow::CheckCalibEnable()
{
    if (m_bIsLeftImgIsLoaded && m_bIsRightImgIsLoaded && m_bParaAccepted) {

        ui->btn_StereoCalib->setEnabled(true);
        ui->btn_ExtractFeatures->setEnabled(true);
        ui->btn_CalDepth->setEnabled(true);
        ui->btn_SaveData->setEnabled(true);
        ui->btn_LoadDisparity->setEnabled(true);
        return true;
    }
    else {
        ui->btn_StereoCalib->setEnabled(false);
        ui->btn_ExtractFeatures->setEnabled(false);
        ui->btn_CalDepth->setEnabled(false);
        ui->btn_SaveData->setEnabled(false);
        ui->btn_LoadDisparity->setEnabled(false);
        return false;
    }
}

bool MainWindow::CheckCalErrorEnable()
{
    if (m_bIsDepthCalculated && m_bIsDisparityImgLoaded) {

        ui->btn_CalError->setEnabled(true);
        return true;
    }
    else {
        ui->btn_CalError->setEnabled(false);
        return false;
    }
    return false;
}

bool MainWindow::CheckContinuousProcessEnable()
{
    if (m_bLeftImgDirIsReady && m_bRightImgDirIsReady && m_bParaAccepted) {
        ui->btn_AutoStart->setEnabled(true);
        return true;
    }
    else {
        ui->btn_AutoStart->setEnabled(false);
        return false;
    }
}

std::vector<cv::DMatch> MainWindow::DisFilter(const std::vector<cv::DMatch>& vInputMatch)
{
    //距离滤波，过滤掉所有描述子距离大于两倍最小距离的匹配
    auto min_max = minmax_element(vInputMatch.begin(), vInputMatch.end(),
        [](const cv::DMatch& m1, const cv::DMatch& m2) {return m1.distance < m2.distance; });
    double dMinDist = min_max.first->distance;
    double dMaxDist = min_max.second->distance;
    std::vector<cv::DMatch> goodMatches;
    for (int i = 0; i < imgFeatureInformation.descriptors1.rows; i++) {
        if (vInputMatch[i].distance <= qMax(2 * dMinDist, 30.0)) {
            goodMatches.push_back(vInputMatch[i]);
        }
    }
    return goodMatches;
}

std::vector<cv::DMatch> MainWindow::CosFilter(const std::vector<cv::DMatch>& vInputMatch,
    const cv::Mat& descriptors1, const cv::Mat& descriptors2)
{
    //余弦滤波，求所有匹配点描述子向量的余弦值，求出平均余弦值，过滤掉所有小于平均余弦值的匹配
    std::vector<float> vec_all1;//矩阵第一行的向量
    std::vector<float> vec_all2;
    std::vector<float>vec_all3;//用于清空vec_all1和vec_all2的向量
    double cosine_sum = 0;
    double cosine_average;
    double value;
    std::vector<double> value_all;
    for (int i = 0; i < vInputMatch.size(); i++)
    {
        const int* data1 = descriptors1.ptr<int>(vInputMatch[i].queryIdx);
        const int* data2 = descriptors2.ptr<int>(vInputMatch[i].trainIdx);
        for (int j = 0; j < 128; j++)
        {
            int vec1 = data1[j];//读取描述子矩阵的一行的128个描述子，也就是某个特征点的描述子
            int vec2 = data2[j];
            vec_all1.push_back(vec1);//把描述子加入到一个向量中
            vec_all2.push_back(vec2);
        }
        value = cosine(vec_all1, vec_all2);//计算两个特征点的余弦值
        value_all.push_back(value);
        cosine_sum = cosine_sum + value;//将余弦值加总
        vec_all1.swap(vec_all3);
        vec_all2.swap(vec_all3);
    }
    cosine_average = cosine_sum / vInputMatch.size();//求取平均余弦值
    std::vector<cv::DMatch>angle_matches;
    for (int n = 0; n < vInputMatch.size(); n++)
    {
        if (value_all[n] > cosine_average) //与平均余弦值作比较 大于平均余弦值的加入到匹配中
        {
            angle_matches.push_back(vInputMatch[n]);
        }
    }
    return angle_matches;
}

std::vector<cv::DMatch> MainWindow::AverDisFilter(const std::vector<cv::DMatch>& vInputMatch)
{
    //平均距离滤波，过滤掉所有描述子距离大于0.7倍平均距离的匹配
    std::vector<cv::DMatch> goodMatches;
    float fAverDist = 0;
    float fSumDist = 0;
    for (int i = 0; i < vInputMatch.size(); i++)
    {
        fSumDist += vInputMatch[i].distance;
    }
    fAverDist = fSumDist / vInputMatch.size();
    for (int i = 0; i < vInputMatch.size(); i++)
    {
        if (vInputMatch[i].distance <= 0.7 * fAverDist) {
            goodMatches.push_back(vInputMatch[i]);
        }
    }
    return goodMatches;
}

std::vector<cv::DMatch> MainWindow::StereoRuleFilter(const std::vector<cv::KeyPoint>& vKeyPoints1,
    const std::vector<cv::KeyPoint>& vKeyPoints2, const std::vector<cv::DMatch>& vInputMatch)
{
    //基于规则的滤波，左右特征点的视差必须为正，且必须行对齐
    std::vector<cv::DMatch> goodMatches;
    for (int i = 0; i < vInputMatch.size(); i++)
    {
        float fParallax = vKeyPoints1[vInputMatch[i].queryIdx].pt.x - vKeyPoints2[vInputMatch[i].trainIdx].pt.x;
        float fHeightDiff = qAbs(vKeyPoints1[vInputMatch[i].queryIdx].pt.y - vKeyPoints2[vInputMatch[i].trainIdx].pt.y);
        //若配对的特征点的视差为正，且高度差在5个像素内，则认为是正确匹配
        if (fParallax > 0) {
            goodMatches.push_back(vInputMatch[i]);
        }
    }
    return goodMatches;
}

std::vector<cv::DMatch> MainWindow::LocationFilter(const std::vector<cv::KeyPoint>& vKeyPoints1,
    const std::vector<cv::KeyPoint>& vKeyPoints2, const std::vector<cv::DMatch>& vInputMatch)
{
    //map存储选择结果，初始全部为true，随着筛选将某些值更改为false，最终输出所有flag为true的结果
    std::vector<bool> keyPointSelectResult;
    for (int i = 0; i < vInputMatch.size(); i++)
    {
        keyPointSelectResult.push_back(true);
    }
    //遍历所有匹配，按顺序选择，选中第i个点时，将其100*100像素范围内所有匹配的flag置为false
    for (int i = 0; i < vInputMatch.size(); i++)
    {
        //std::cout << "keyPointSelectResult[i]: " << keyPointSelectResult[i] << std::endl;
        if (keyPointSelectResult[i] == false) {
            continue;
        }
        cv::KeyPoint keyPointCurrent = vKeyPoints1[vInputMatch[i].queryIdx];
        for (int j = 0; j < vInputMatch.size(); j++)
        {
            if (i == j) {
                continue;
            }
            cv::KeyPoint keyPointCompare = vKeyPoints1[vInputMatch[j].queryIdx];
            if (qAbs(keyPointCurrent.pt.x - keyPointCompare.pt.x) <= 10 ||
                qAbs(keyPointCurrent.pt.y - keyPointCompare.pt.y) <= 10) {
                keyPointSelectResult[j] = false;
            }
        }
    }
    std::vector<cv::DMatch> goodMatches;
    for (int i = 0; i < keyPointSelectResult.size(); i++)
    {
        if (keyPointSelectResult[i] == true) {
            goodMatches.push_back(vInputMatch[i]);
        }
    }
    return goodMatches;
}

//std::vector<cv::DMatch> MainWindow::RansacFilter(cv::Mat imgLeft, std::vector<cv::DMatch> vInputMatch,
//    std::vector<cv::KeyPoint> vKeyPointLeft, std::vector<cv::KeyPoint> vKeyPointRight)
//{
//    //RANSAC滤波，利用RANSAC方法计算inputMatch的基础矩阵，保留所有内点
//    std::vector<cv::DMatch> m_Matches = vInputMatch;
//
//    std::cout << "m_Matches=" << m_Matches.size() << std::endl;
//    // 分配空间
//    int ptCount = (int)m_Matches.size();
//    cv::Mat p1(ptCount, 2, CV_32F);
//    cv::Mat p2(ptCount, 2, CV_32F);
//    // 把Keypoint转换为Mat
//    cv::Point2f pt;
//    for (int i = 0; i < ptCount; i++)
//    {
//        pt = vKeyPointLeft[m_Matches[i].queryIdx].pt;
//        p1.at<float>(i, 0) = pt.x;
//        p1.at<float>(i, 1) = pt.y;
//        pt = vKeyPointRight[m_Matches[i].trainIdx].pt;
//        p2.at<float>(i, 0) = pt.x;
//        p2.at<float>(i, 1) = pt.y;
//    }
//    //cout<<"p1="<<p1<<endl;//图1的匹配点坐标
//    //cout<<"p2="<<p2<<endl;//图2的匹配点坐标
//    // 用RANSAC方法计算F(基础矩阵)
//    cv::Mat m_Fundamental;
//    std::vector<uchar> m_RANSACStatus;       // 这个变量用于存储RANSAC后每个点的状态
//    findFundamentalMat(p1, p2, m_RANSACStatus, cv::FM_RANSAC);
//    // 计算内点个数
//    int OutlinerCount = 0;
//    for (int i = 0; i < ptCount; i++)
//    {
//        if (m_RANSACStatus[i] == 0)    // 状态为0表示外点
//        {
//            OutlinerCount++;
//        }
//    }
//    int InlinerCount = ptCount - OutlinerCount;   // 计算内点   
//    std::cout << "内点数为 " << InlinerCount << std::endl;
//    std::cout << "外点数为 " << OutlinerCount << std::endl;
//    // 这三个变量用于保存内点和匹配关系
//    std::vector<cv::Point2f> m_LeftInlier;
//    std::vector<cv::Point2f> m_RightInlier;
//    std::vector<cv::DMatch> m_InlierMatches;
//    m_InlierMatches.resize(InlinerCount);
//    m_LeftInlier.resize(InlinerCount);
//    m_RightInlier.resize(InlinerCount);
//    InlinerCount = 0;
//    float inlier_minRx = imgLeft.cols;        //用于存储内点中右图最小横坐标，以便后续融合
//
//    for (int i = 0; i < ptCount; i++)
//    {
//        if (m_RANSACStatus[i] != 0)
//        {
//            m_LeftInlier[InlinerCount].x = p1.at<float>(i, 0);
//            m_LeftInlier[InlinerCount].y = p1.at<float>(i, 1);
//            m_RightInlier[InlinerCount].x = p2.at<float>(i, 0);
//            m_RightInlier[InlinerCount].y = p2.at<float>(i, 1);
//            m_InlierMatches[InlinerCount].queryIdx = InlinerCount;
//            m_InlierMatches[InlinerCount].trainIdx = InlinerCount;
//
//        }
//        //存储内点中右图最小横坐标
//        if (m_RightInlier[InlinerCount].x < inlier_minRx) {
//            inlier_minRx = m_RightInlier[InlinerCount].x;
//        }
//        InlinerCount++;
//    }
//    std::cout << "inlier_minRx=" << inlier_minRx << std::endl;
//    // 把内点转换为drawMatches可以使用的格式
//    std::vector<cv::KeyPoint> key1(InlinerCount);
//    std::vector<cv::KeyPoint> key2(InlinerCount);
//    cv::KeyPoint::convert(m_LeftInlier, key1);
//    cv::KeyPoint::convert(m_RightInlier, key2);
//    return m_InlierMatches;
//    //// 显示计算F过后的内点匹配
//    //Mat OutImage;
//    //drawMatches(img1, key1, img2, key2, m_InlierMatches, OutImage, CV_RGB(255, 0, 255), CV_RGB(0, 255, 0));
//    //imshow("RANSAC match features", OutImage);
//    //imwrite("RansacMatch.tif", OutImage);
//}

void MainWindow::Slot_OpenImgBtn_clicked()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Open Image", ".", "Image Files(*.png *.jpg *.jpeg)");
    if (!fileName.isEmpty())
    {
        QObject* pSender = sender();
        if (Q_NULLPTR != pSender) {
            if (pSender->objectName() == "btn_OpenLeftImg") {
                if (!LoadImageFromPath(fileName, m_showImageArea::left)) {
                    QMessageBox::critical(this, "Error", "Failed when opening the image");
                    return;
                }
                ShowImage(m_imgLeft, m_showImageArea::left);
            }
            else if (pSender->objectName() == "btn_OpenRightImg") {
                if (!LoadImageFromPath(fileName, m_showImageArea::right)) {
                    QMessageBox::critical(this, "Error", "Failed when opening the image");
                    return;
                }
                ShowImage(m_imgRight, m_showImageArea::right);
            }
        }
    }
    CheckCalibEnable();
}

bool MainWindow::Slot_StereoCalibBtn_clicked()
{
    if (!CheckImgSize()) {
        emit Signal_StopAutoMode();
        return false;
    };
    //从配置中获取立体校正需要的参数
    cv::Mat Cam0Matrix = m_pConigWindow->m_pCameraPara->cam0Para->intrinsic;
    cv::Mat Cam0Distortion = m_pConigWindow->m_pCameraPara->cam0Para->distortionCoefficient;
    cv::Mat Cam1Matrix = m_pConigWindow->m_pCameraPara->cam1Para->intrinsic;
    cv::Mat Cam1Distortion = m_pConigWindow->m_pCameraPara->cam1Para->distortionCoefficient;
    cv::Mat T01 = m_pConigWindow->m_pCameraPara->extrinsicT10;
    cv::Mat R01 = m_pConigWindow->m_pCameraPara->extrinsicT10(cv::Rect(0, 0, 3, 3));
    cv::Mat t01 = m_pConigWindow->m_pCameraPara->extrinsicT10(cv::Rect(3, 0, 1, 3));
    cv::Mat R1, R2, P1, P2, Q;
    myDebug::CvMatDebug(Cam0Matrix, myDebug::m_outputMode::console);
    myDebug::CvMatDebug(Cam0Distortion, myDebug::m_outputMode::console);
    myDebug::CvMatDebug(Cam1Matrix, myDebug::m_outputMode::console);
    myDebug::CvMatDebug(Cam1Distortion, myDebug::m_outputMode::console);
    myDebug::CvMatDebug(T01, myDebug::m_outputMode::console);
    myDebug::CvMatDebug(R01, myDebug::m_outputMode::console);
    myDebug::CvMatDebug(t01, myDebug::m_outputMode::console);
    
    //立体校正
    cv::stereoRectify(Cam0Matrix, Cam0Distortion, Cam1Matrix, Cam1Distortion,
        cv::Size(m_imgLeft.width(), m_imgLeft.height()), R01, t01, R1, R2, P1, P2, Q,
        cv::CALIB_ZERO_DISPARITY, 0);

    //使用R1,P1输出两个映射矩阵
    cv::Mat mapLx, mapLy;
    cv::initUndistortRectifyMap(Cam0Matrix, Cam0Distortion, R1, P1,
        cv::Size(m_imgLeft.width(), m_imgLeft.height()), CV_32FC1, mapLx, mapLy);
    //使用R2,P2输出两个映射矩阵
    cv::Mat mapRx, mapRy;
    cv::initUndistortRectifyMap(Cam1Matrix, Cam1Distortion, R2, P2,
        cv::Size(m_imgLeft.width(), m_imgLeft.height()), CV_32FC1, mapRx, mapRy);
    cv::Mat ImageL, ImageR;
    ImageL = ImageHandle::QImage2Mat(m_imgLeft);
    ImageR = ImageHandle::QImage2Mat(m_imgRight);
    if (ImageL.empty() || ImageR.empty()) {
        QMessageBox::critical(this, "Error", "Image is empty");
    }
    //将双目矫正后的图像放入rectifyImageL2和rectifyImageR2中
    cv::Mat rectifyImageL2, rectifyImageR2;
    cv::remap(ImageL, rectifyImageL2, mapLx, mapLy, cv::INTER_LINEAR);
    cv::remap(ImageR, rectifyImageR2, mapRx, mapRy, cv::INTER_LINEAR);

    //保存校正得到的结果
    m_pConigWindow->m_pCameraPara->cam0Para->correctionR = std::move(R1);
    m_pConigWindow->m_pCameraPara->cam0Para->projectionMatrix = std::move(P1);
    m_pConigWindow->m_pCameraPara->cam1Para->correctionR = std::move(R2);
    m_pConigWindow->m_pCameraPara->cam1Para->projectionMatrix = std::move(P2);
    m_pConigWindow->m_pCameraPara->Q = std::move(Q);
    configuration::GetCalibShowParaFromCam(*m_pConigWindow->m_pCameraPara, *m_pConigWindow->m_pShowPara);
    //显示立体校正的结果
    ShowCalibData();
    //保存校正图像并显示
    m_rectifyImgLeft = ImageHandle::Mat2QImage(rectifyImageL2);
    m_rectifyImgRight = ImageHandle::Mat2QImage(rectifyImageR2);

    QObject* pSender = sender();
    if (Q_NULLPTR != pSender) {
        if (pSender->objectName() == "btn_StereoCalib") {
            ShowImage(m_rectifyImgLeft, m_showImageArea::left);
            ShowImage(m_rectifyImgRight, m_showImageArea::right);
        }
        else {
            //ShowCalibImage(m_showImageArea::left);
            //ShowCalibImage(m_showImageArea::right);
        }
    }

    m_bIsStereoCalibrated = true;
    
    return true;
}

bool MainWindow::Slot_ExtractFeaturesBtn_clicked()
{
    if (!m_bIsStereoCalibrated) {
        QMessageBox::warning(this, QString("Warning"), QString("Please calibrate the camera first"));
        return false;
    }
    
    ORBfeatureMatch();

    //为每对特征匹配生成配色
    float fLineColor1 = 0.f;
    float fLineColor2 = 0.f;
    float fLineColor3 = 0.f;
    imgFeatureInformation.vColor.clear();
    for (int i = 0; i < imgFeatureInformation.matches.size(); i++)
    {
        fLineColor1 = (float)QRandomGenerator::global()->bounded(1.0) * 255;
        fLineColor2 = (float)QRandomGenerator::global()->bounded(1.0) * 255;
        fLineColor3 = (float)QRandomGenerator::global()->bounded(1.0) * 255;
        imgFeatureInformation.vColor.push_back(cv::Scalar(fLineColor1, fLineColor2, fLineColor3));
    }

    //绘制匹配结果并显示
    cv::Mat imgMatches = DrawMatches(ImageHandle::QImage2Mat(m_rectifyImgLeft),ImageHandle::QImage2Mat(m_rectifyImgRight),
        imgFeatureInformation.vKeyPoints1, imgFeatureInformation.vKeyPoints2, imgFeatureInformation.matches,
        imgFeatureInformation.vColor);
    QImage imgMatchesShow = ImageHandle::Mat2QImage(imgMatches);
    ShowImage(imgMatchesShow, m_showImageArea::featureMatch);

    //转为灰度图保存
    cv::Mat imgMatchesGray;
    cv::cvtColor(imgMatches, imgMatchesGray, cv::COLOR_BGR2GRAY);
    m_featureMatchImg = ImageHandle::Mat2QImage(imgMatchesGray);

    m_bIsFeatureExtracted = true;

    return true;
}

bool MainWindow::Slot_CalDepthBtn_clicked()
{
    //检查操作是否合法
    if (!m_bIsStereoCalibrated) {
        QMessageBox::warning(this, QString("Warning"), QString("Please calibrate the camera"));
        return false;
    }
    if (!m_bIsFeatureExtracted) {
        QMessageBox::warning(this, QString("Warning"), QString("Please extract features"));
        return false;
    }

    imgFeatureInformation.vParallax.clear();
    imgFeatureInformation.v3dPoints.clear();
    //求匹配点的视差
    for (int i = 0; i < imgFeatureInformation.matches.size(); i++)
    {
        qint16 nLeftKpIdx = imgFeatureInformation.matches[i].queryIdx;
        qint16 nRightKpIdx = imgFeatureInformation.matches[i].trainIdx;
        qint16 nUl = imgFeatureInformation.vKeyPoints1[nLeftKpIdx].pt.x;
        qint16 nUr = imgFeatureInformation.vKeyPoints2[nRightKpIdx].pt.x;
        imgFeatureInformation.vParallax.push_back(nUl - nUr);
    }

    //利用Q矩阵求三维点坐标
    for (int i = 0; i < imgFeatureInformation.vParallax.size(); i++)
    {
        cv::Mat _3dCoor;
        cv::Mat _2dCoor = cv::Mat::zeros(4, 1, CV_64F);
        _2dCoor.at<double>(0, 0) = imgFeatureInformation.vKeyPoints1[imgFeatureInformation.matches[i].queryIdx].pt.x;
        _2dCoor.at<double>(1, 0) = imgFeatureInformation.vKeyPoints1[imgFeatureInformation.matches[i].queryIdx].pt.y;
        _2dCoor.at<double>(2, 0) = imgFeatureInformation.vParallax[i];
        _2dCoor.at<double>(3, 0) = 1;
        _3dCoor = m_pConigWindow->m_pCameraPara->Q * _2dCoor;
        double Xw = _3dCoor.at <double>(0, 0);
        double Yw = _3dCoor.at <double>(1, 0);
        double Zw = _3dCoor.at <double>(2, 0);
        double W = _3dCoor.at <double>(3, 0);
        imgFeatureInformation.v3dPoints.push_back(cv::Point3d(Xw / W, Yw / W, Zw / W));
    }

    //打印计算结果
    for (int i = 0; i < imgFeatureInformation.matches.size(); i++)
    {
        cv::Point2d left2dPoint = imgFeatureInformation.vKeyPoints1[imgFeatureInformation.matches[i].queryIdx].pt;
        cv::Point2d right2dPoint = imgFeatureInformation.vKeyPoints2[imgFeatureInformation.matches[i].trainIdx].pt;
        std::cout << "Point NO: " << i << std::endl;
        std::cout << "Left point: " << left2dPoint << std::endl;
        std::cout << "Right point: " << right2dPoint << std::endl;
        std::cout << "Parallax: " << imgFeatureInformation.vParallax[i] << std::endl;
        std::cout << "3dCoor: " << imgFeatureInformation.v3dPoints[i] << std::endl << std::endl;
    }

    //绘制匹配
    cv::Mat imgMatches = DrawMatches(ImageHandle::QImage2Mat(m_rectifyImgLeft), ImageHandle::QImage2Mat(m_rectifyImgRight),
        imgFeatureInformation.vKeyPoints1, imgFeatureInformation.vKeyPoints2, imgFeatureInformation.matches,
        imgFeatureInformation.vColor);
    //绘制深度
    imgMatches = DrawDepth(imgMatches, imgFeatureInformation.vKeyPoints1, imgFeatureInformation.matches,
        imgFeatureInformation.v3dPoints, imgFeatureInformation.vColor);
    //显示在界面
    QImage imgMatchesShow = ImageHandle::Mat2QImage(imgMatches);
    ShowImage(imgMatchesShow, m_showImageArea::featureMatch);
    
    //三维可视化
    if (Q_NULLPTR == m_pOpenGLWidget) {
        m_pOpenGLWidget = new OpenGLWidget(ui->groupBox_3dViewer);
        m_pOpenGLWidget->setGeometry(20, 20, ui->groupBox_3dViewer->width() - 40, ui->groupBox_3dViewer->height() - 40);
    }
    m_pOpenGLWidget->show();
    m_pOpenGLWidget->SetLineData(imgFeatureInformation.v3dPoints, imgFeatureInformation.vColor);

    m_bIsDepthCalculated = true;

    CheckCalErrorEnable();

    return true;
}

void MainWindow::Slot_SaveDataBtn_clicked()
{
    //检查操作是否合法
    if (!m_bIsStereoCalibrated) {
        QMessageBox::warning(this, QString("Warning"), QString("Please calibrate the camera"));
        return;
    }
    if (!m_bIsFeatureExtracted) {
        QMessageBox::warning(this, QString("Warning"), QString("Please extract features"));
        return;
    }
    if (!m_bIsDepthCalculated) {
        QMessageBox::warning(this, QString("Warning"), QString("Please calculate points"));
        return;
    }

    //文件名
    static QString sResFileName = "result.json";
    static QString sResFileFullPath = QString("%1/%2").arg(m_sExePath).arg(sResFileName);
    //若已存在则删除
    QFileInfo m_ResFileInfo(sResFileFullPath);
    if (m_ResFileInfo.isFile()) {
        QFile::remove(sResFileFullPath);
    }
    //实例化文件
    if (Q_NULLPTR == m_pResFile) {
        m_pResFile = new QFile;
        m_pResFile->setFileName(sResFileFullPath);
    }
    
    //处理json
    QJsonArray resArray;
    for (int i = 0; i < imgFeatureInformation.matches.size(); i++)
    {
        //序号
        QJsonValue index(i);
        //左侧图像特征点像素坐标
        QJsonArray keyPointLeftArr;
        cv::Point2d left2dPoint = imgFeatureInformation.vKeyPoints1[imgFeatureInformation.matches[i].queryIdx].pt;
        keyPointLeftArr.push_back(QString::number(left2dPoint.x, 'f', 1));
        keyPointLeftArr.push_back(QString::number(left2dPoint.y, 'f', 1));
        //右侧图像特征点像素坐标
        QJsonArray keyPointRightArr;
        cv::Point2d right2dPoint = imgFeatureInformation.vKeyPoints2[imgFeatureInformation.matches[i].trainIdx].pt;
        keyPointRightArr.push_back(QString::number(right2dPoint.x, 'f', 1));
        keyPointRightArr.push_back(QString::number(right2dPoint.y, 'f', 1));
        //视差
        QJsonValue parallax(imgFeatureInformation.vParallax[i]);
        //三维坐标
        QJsonArray _3dPointArr;
        cv::Point3d _3dPoint = imgFeatureInformation.v3dPoints[i];
        _3dPointArr.push_back(QString::number(_3dPoint.x, 'f', 3));
        _3dPointArr.push_back(QString::number(_3dPoint.y, 'f', 3));
        _3dPointArr.push_back(QString::number(_3dPoint.z, 'f', 3));

        QJsonObject matchObj;
        matchObj.insert("index", index);
        matchObj.insert("keyPointLeft", keyPointLeftArr);
        matchObj.insert("keyPointRight", keyPointRightArr);
        matchObj.insert("parallax", parallax);
        matchObj.insert("res3dCoor", _3dPointArr);

        resArray.push_back(matchObj);
    }

    QJsonDocument resDoc(resArray);
    QByteArray resByteArr = resDoc.toJson();
    
    if (!m_pResFile->open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this, "Error", "Failed when opening the file 'result.json'");
    }
    m_pResFile->write(resByteArr);
    m_pResFile->close();

    QMessageBox::information(this, "Infomation", "写入成功");
}

void MainWindow::Slot_LoadDisparityBtn_clicked() {
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Open Image", ".", "Image Files(*.png *.jpg *.jpeg)");
    if (!fileName.isEmpty())
    {
        //若读取失败
        if (!LoadImageFromPath(fileName, m_showImageArea::disparity)) {
            QMessageBox::critical(this, "Error", "Failed when opening the image");
            return;
        }
        ShowImage(m_disparityImg, m_showImageArea::disparity);
    }
    CheckCalErrorEnable();
}

void MainWindow::Slot_CalErrorBtn_clicked() {
    cv::Mat disparityImg = ImageHandle::QImage2Mat(m_disparityImg);
    //计算误差
    imgFeatureInformation.vError.clear();
    for (int i = 0; i < imgFeatureInformation.matches.size(); i++)
    {
        cv::Point2d left2dPoint = imgFeatureInformation.vKeyPoints1[imgFeatureInformation.matches[i].queryIdx].pt;
        cv::Point2d right2dPoint = imgFeatureInformation.vKeyPoints2[imgFeatureInformation.matches[i].trainIdx].pt;
        qint16 nParallax = imgFeatureInformation.vParallax[i];
        qint16 nDisparity = (int)disparityImg.at<uchar>(left2dPoint);
        std::cout << "Point NO: " << i << std::endl;
        std::cout << "Parallax: " << nParallax << std::endl;
        std::cout << "Disparity: " << nDisparity << std::endl << std::endl;

        imgFeatureInformation.vError.push_back(qAbs(nParallax - nDisparity) / (float)nDisparity);
    }

    //绘制匹配
    cv::Mat imgMatches = DrawMatches(ImageHandle::QImage2Mat(m_rectifyImgLeft), ImageHandle::QImage2Mat(m_rectifyImgRight),
        imgFeatureInformation.vKeyPoints1, imgFeatureInformation.vKeyPoints2, imgFeatureInformation.matches,
        imgFeatureInformation.vColor);
    //绘制深度
    imgMatches = DrawDepthAndError(imgMatches, imgFeatureInformation.vKeyPoints1, imgFeatureInformation.matches,
        imgFeatureInformation.v3dPoints, imgFeatureInformation.vError, imgFeatureInformation.vColor);
    //显示在界面
    QImage imgMatchesShow = ImageHandle::Mat2QImage(imgMatches);
    ShowImage(imgMatchesShow, m_showImageArea::featureMatch);

    //更新三维可视化数据
    m_pOpenGLWidget->show();
    //加载新数据
    m_pOpenGLWidget->SetLineData(imgFeatureInformation.v3dPoints, imgFeatureInformation.vError);
}

void MainWindow::Slot_ModifyParaBtn_clicked()
{
    m_pConigWindow->show();
}

void MainWindow::Slot_OpenDirBtn_clicked()
{
    //获取路径名称
    QString sDirName;
    sDirName = QFileDialog::getExistingDirectory(this, "Open Dir", "", QFileDialog::DontResolveSymlinks);
    QDir currentDir(sDirName);

    //记录左右侧文件夹，及文件夹下所有图片名
    if (!sDirName.isEmpty())
    {
        QObject* pSender = sender();
        if (Q_NULLPTR != pSender) {
            if (pSender->objectName() == "btn_SelectDirLeft") {
                m_sImgDirLeft = currentDir;
                //获取路径下所有后缀为.jpg/.png的文件名
                QStringList nameFilter;
                nameFilter << "*.jpg" << "*.png";
                QStringList imgNames = currentDir.entryList(nameFilter, QDir::Files, QDir::Name);
                //保存所有文件名
                m_ImgNameList = std::move(imgNames);
                m_itImgName = m_ImgNameList.begin();
                m_bLeftImgDirIsReady = true;
                QMessageBox::information(this, "Information", QString("Selected successfully, %1 images are loaded")
                    .arg(m_ImgNameList.size()));
            }
            else if (pSender->objectName() == "btn_SelectDirRight") {
                m_sImgDirRight = currentDir;
                m_bRightImgDirIsReady = true;
                QMessageBox::information(this, "Information", "Selected successfully");
            }
        }
    }
    CheckContinuousProcessEnable();
}

void MainWindow::Slot_AutoStartBtn_clicked()
{
    if (Q_NULLPTR == loadNextImgTimer) {
        loadNextImgTimer = new QTimer;
    }
    loadNextImgTimer->start(20);
    ui->btn_Pause->setEnabled(true);
    ui->btn_NextImg->setEnabled(false);
    ui->btn_Reset->setEnabled(false);
}

void MainWindow::Slot_ProcessNextImg()
{
    //检查是否已经处理完毕所有图像
    if (m_itImgName == m_ImgNameList.end()) {
        QMessageBox::information(this, "Information", "No more image can be processed");
        loadNextImgTimer->stop();
        ui->btn_Pause->setEnabled(false);
        ui->btn_Reset->setEnabled(true);
        return;
    }
    //检查左侧图像文件夹是否存在
    if (!m_sImgDirLeft.exists()) {
        m_bLeftImgDirIsReady = false;
        CheckContinuousProcessEnable();
        QMessageBox::critical(this, "Error", "The left image directory not exist");
        return;
    }
    //检查右侧图像文件夹是否存在
    if (!m_sImgDirRight.exists()) {
        m_bRightImgDirIsReady = false;
        CheckContinuousProcessEnable();
        QMessageBox::critical(this, "Error", "The right image directory not exist");
        return;
    }
    //检查左右侧图像是否同时存在，同时存在则处理，否则读取下一张图
    QString sLeftImgPath = QString("%1/%2").arg(m_sImgDirLeft.absolutePath()).arg(*m_itImgName);
    QFileInfo leftImgInfo(sLeftImgPath);
    QString sRightImgPath = QString("%1/%2").arg(m_sImgDirRight.absolutePath()).arg(*m_itImgName);
    QFileInfo rightImgInfo(sRightImgPath);
    if (!leftImgInfo.isFile() || !rightImgInfo.isFile()) {
        m_itImgName++;
        Slot_ProcessNextImg();
        return;
    }
    //左右侧图像同时存在
    else {
        ui->label_ImgName->setText(*m_itImgName);
        //从文件路径加载图像
        LoadImageFromPath(sLeftImgPath, m_showImageArea::left);
        LoadImageFromPath(sLeftImgPath, m_showImageArea::right);
        //显示在界面
        ShowImage(m_imgLeft, m_showImageArea::left);
        ShowImage(m_imgRight, m_showImageArea::right);
        //立体校正
        if (!Slot_StereoCalibBtn_clicked()) {
            return;
        }
        //特征提取
        if (!Slot_ExtractFeaturesBtn_clicked()) {
            return;
        }
        //计算深度
        if (!Slot_CalDepthBtn_clicked()) {
            return;
        }
        m_itImgName++;
    }
}

void MainWindow::Slot_PauseBtn_clicked()
{
    loadNextImgTimer->stop();
    ui->btn_NextImg->setEnabled(true);
    ui->btn_Reset->setEnabled(true);
}

void MainWindow::Slot_ImgDirIsReady()
{
    ui->btn_AutoStart->setEnabled(true);
    ui->btn_Pause->setEnabled(true);
}

void MainWindow::Slot_StopAutoMode() {
    loadNextImgTimer->stop();
    ui->btn_AutoStart->setEnabled(false);
    ui->btn_Pause->setEnabled(false);
    ui->btn_NextImg->setEnabled(false);
    ui->btn_Reset->setEnabled(false);
}

void MainWindow::Slot_NextImg_clicked()
{
    Slot_ProcessNextImg();
}

void MainWindow::Slot_Reset_clicked()
{
    //从头开始读取
    m_itImgName = m_ImgNameList.begin();
    //处理第一张图
    Slot_ProcessNextImg();
}

void MainWindow::Slot_ParaAccepted(bool success)
{
    if (success) {
        m_bParaAccepted = true;
        //参数发生改变，重置系统
        m_bIsStereoCalibrated = false;
        m_bIsFeatureExtracted = false;
        m_bIsDepthCalculated = false;
        m_bIsDisparityImgLoaded = false;
        CheckCalibEnable();
        CheckContinuousProcessEnable();
        CheckCalErrorEnable();

        //主窗口显示cam0参数
        ui->textEdit_TBS_cam0_show->setText(m_pConigWindow->m_pShowPara->cam0ShowPara->sExtrinsicTBC);
        ui->lineEdit_rate_cam0_show->setText(m_pConigWindow->m_pShowPara->cam0ShowPara->sRate);
        ui->lineEdit_resolution_cam0_show->setText(m_pConigWindow->m_pShowPara->cam0ShowPara->sResolution);
        ui->lineEdit_camera_model_cam0_show->setText(m_pConigWindow->m_pShowPara->cam0ShowPara->sCameraModel);
        ui->lineEdit_fu_cam0_show->setText(m_pConigWindow->m_pShowPara->cam0ShowPara->sFu);
        ui->lineEdit_fv_cam0_show->setText(m_pConigWindow->m_pShowPara->cam0ShowPara->sFv);
        ui->lineEdit_cu_cam0_show->setText(m_pConigWindow->m_pShowPara->cam0ShowPara->sCu);
        ui->lineEdit_cv_cam0_show->setText(m_pConigWindow->m_pShowPara->cam0ShowPara->sCv);
        ui->lineEdit_distortion_model_cam0_show->setText(m_pConigWindow->m_pShowPara->cam0ShowPara->sDistortionModel);
        ui->textEdit_coefficients_cam0_show->setText(m_pConigWindow->m_pShowPara->cam0ShowPara->sDistortion);

        //主窗口显示cam1参数
        ui->textEdit_TBS_cam1_show->setText(m_pConigWindow->m_pShowPara->cam1ShowPara->sExtrinsicTBC);
        ui->lineEdit_rate_cam1_show->setText(m_pConigWindow->m_pShowPara->cam1ShowPara->sRate);
        ui->lineEdit_resolution_cam1_show->setText(m_pConigWindow->m_pShowPara->cam1ShowPara->sResolution);
        ui->lineEdit_camera_model_cam1_show->setText(m_pConigWindow->m_pShowPara->cam1ShowPara->sCameraModel);
        ui->lineEdit_fu_cam1_show->setText(m_pConigWindow->m_pShowPara->cam1ShowPara->sFu);
        ui->lineEdit_fv_cam1_show->setText(m_pConigWindow->m_pShowPara->cam1ShowPara->sFv);
        ui->lineEdit_cu_cam1_show->setText(m_pConigWindow->m_pShowPara->cam1ShowPara->sCu);
        ui->lineEdit_cv_cam1_show->setText(m_pConigWindow->m_pShowPara->cam1ShowPara->sCv);
        ui->lineEdit_distortion_model_cam1_show->setText(m_pConigWindow->m_pShowPara->cam1ShowPara->sDistortionModel);
        ui->textEdit_coefficients_cam1_show->setText(m_pConigWindow->m_pShowPara->cam1ShowPara->sDistortion);
    }
    else {
        //重置系统
        m_bParaAccepted = false;
        m_bIsStereoCalibrated = false;
        m_bIsFeatureExtracted = false;
        m_bIsDepthCalculated = false;
        m_bIsDisparityImgLoaded = false;
        CheckCalibEnable();
        CheckContinuousProcessEnable();
        CheckCalErrorEnable();

        //cam0显示清空
        ui->textEdit_TBS_cam0_show->setText("");
        ui->lineEdit_rate_cam0_show->setText("");
        ui->lineEdit_resolution_cam0_show->setText("");
        ui->lineEdit_camera_model_cam0_show->setText("");
        ui->lineEdit_fu_cam0_show->setText("");
        ui->lineEdit_fv_cam0_show->setText("");
        ui->lineEdit_cu_cam0_show->setText("");
        ui->lineEdit_cv_cam0_show->setText("");
        ui->lineEdit_distortion_model_cam0_show->setText("");
        ui->textEdit_coefficients_cam0_show->setText("");
        ui->textEdit_RCor_cam0_show->setText("");
        ui->textEdit_Proj_cam0_show->setText("");

        //cam1显示清空
        ui->textEdit_TBS_cam1_show->setText("");
        ui->lineEdit_rate_cam1_show->setText("");
        ui->lineEdit_resolution_cam1_show->setText("");
        ui->lineEdit_camera_model_cam1_show->setText("");
        ui->lineEdit_fu_cam1_show->setText("");
        ui->lineEdit_fv_cam1_show->setText("");
        ui->lineEdit_cu_cam1_show->setText("");
        ui->lineEdit_cv_cam1_show->setText("");
        ui->lineEdit_distortion_model_cam1_show->setText("");
        ui->textEdit_coefficients_cam1_show->setText("");
        ui->textEdit_RCor_cam1_show->setText("");
        ui->textEdit_Proj_cam1_show->setText("");

        //外参显示清空
        ui->textEdit_T10_show->setText("");
        ui->textEdit_Q_show->setText("");
    }
}


void MainWindow::mousePressEvent(QMouseEvent* event)
{
    setFocusPolicy(Qt::NoFocus);
}