#include "configuration.h"
#include "errorMessage.h"
#include "myDebug.h"

#include "QFileDialog"
#include "QMessageBox"
#include "QDebug"

#include "opencv2/core/eigen.hpp"

#include <map>
#include <iostream>

configuration::configuration(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    Init();
}

configuration::~configuration()
{
    //析构
    if (Q_NULLPTR != m_pCameraPara) {
        if (Q_NULLPTR != m_pCameraPara->cam0Para) {
            delete m_pCameraPara->cam0Para;
        }
        if (Q_NULLPTR != m_pCameraPara->cam1Para) {
            delete m_pCameraPara->cam1Para;
        }
        delete m_pCameraPara;
    }
    if (Q_NULLPTR != m_pShowPara) {
        if (Q_NULLPTR != m_pShowPara->cam0ShowPara) {
            delete m_pShowPara->cam0ShowPara;
        }
        if (Q_NULLPTR != m_pShowPara->cam1ShowPara) {
            delete m_pShowPara->cam1ShowPara;
        }
        delete m_pShowPara;
    }
}


void configuration::Init() {
    //实例化
    //相机参数
    if (Q_NULLPTR == m_pCameraPara) {
        m_pCameraPara = new cameraPara;
    }
    if (Q_NULLPTR == m_pCameraPara->cam0Para) {
        m_pCameraPara->cam0Para = new singleCamPara;
    }
    if (Q_NULLPTR == m_pCameraPara->cam1Para) {
        m_pCameraPara->cam1Para = new singleCamPara;
    }
    //相机显示参数
    if (Q_NULLPTR == m_pShowPara) {
        m_pShowPara = new showPara;
    }
    if (Q_NULLPTR == m_pShowPara->cam0ShowPara) {
        m_pShowPara->cam0ShowPara = new singleCamShowPara;
    }
    if (Q_NULLPTR == m_pShowPara->cam1ShowPara) {
        m_pShowPara->cam1ShowPara = new singleCamShowPara;
    }

    //connect
    connect(ui.btn_Confirm_cam0, &QPushButton::clicked, this, &configuration::Slot_ConfirmBtn_clicked);
    connect(ui.btn_Confirm_cam1, &QPushButton::clicked, this, &configuration::Slot_ConfirmBtn_clicked);

	connect(ui.btn_LoadFromFile_cam0, &QPushButton::clicked, this, &configuration::Slot_LoadFromFileBtn_clicked);
    connect(ui.btn_LoadFromFile_cam1, &QPushButton::clicked, this, &configuration::Slot_LoadFromFileBtn_clicked);

}

bool configuration::CheckShowDataExp(singleCamShowPara showData) {
    //数字正则，正负数、整数小数、科学计数法均合法
    QRegExp numberRx("^(-?[0-9]+(\.[0-9]+)?(e-?[0-9]+)?)$");
    //正整数正则，正整数合法
    QRegExp integerRx("^([1-9]+[0-9]+)$");
    //字符串正则，只允许大小写字母和'-'
    QRegExp stringRx("^([a-z]|[A-Z]|\-)+$");
    //数字数组分割正则，以,或,\n或\n分割
    QRegExp numberVectorRx(",|,\\s+|\\s+");

    //单值正则检查
    std::map<QString, bool> RegExpMap;
    RegExpMap.insert(std::pair<QString, bool>(QString("Rate"), true));
    RegExpMap.insert(std::pair<QString, bool>(QString("CameraModel"), true));
    RegExpMap.insert(std::pair<QString, bool>(QString("Fu"), true));
    RegExpMap.insert(std::pair<QString, bool>(QString("Fv"), true));
    RegExpMap.insert(std::pair<QString, bool>(QString("Cu"), true));
    RegExpMap.insert(std::pair<QString, bool>(QString("Cv"), true));
    RegExpMap.insert(std::pair<QString, bool>(QString("DistortionModel"), true));

    RegExpMap["Rate"] = integerRx.exactMatch(showData.sRate.trimmed());
    RegExpMap["CameraModel"] = stringRx.exactMatch(showData.sCameraModel.trimmed());
    RegExpMap["Fu"] = numberRx.exactMatch(showData.sFu.trimmed());
    RegExpMap["Fv"] = numberRx.exactMatch(showData.sFv.trimmed());
    RegExpMap["Cu"] = numberRx.exactMatch(showData.sCu.trimmed());
    RegExpMap["Cv"] = numberRx.exactMatch(showData.sCv.trimmed());
    RegExpMap["DistortionModel"] = stringRx.exactMatch(showData.sDistortionModel.trimmed());

    //数组正则检查
    RegExpMap.insert(std::pair<QString, bool>(QString("ExtrinsicTBC"), true));
    RegExpMap.insert(std::pair<QString, bool>(QString("Resolution"), true));
    RegExpMap.insert(std::pair<QString, bool>(QString("Distortion"), true));
    QStringList sExtrinsicTBCList = showData.sExtrinsicTBC.split(numberVectorRx, Qt::SkipEmptyParts);
    for (int i = 0; i < sExtrinsicTBCList.size(); i++)
    {
        if (!numberRx.exactMatch(sExtrinsicTBCList[i].trimmed())) {
            RegExpMap["ExtrinsicTBC"] = false;
            break;
        }
    }
    QStringList sResolutionList = showData.sResolution.split(numberVectorRx, Qt::SkipEmptyParts);
    for (int i = 0; i < sResolutionList.size(); i++)
    {
        if (!integerRx.exactMatch(sResolutionList[i].trimmed())) {
            RegExpMap["Resolution"] = false;
            break;
        }
    }
    QStringList sDistortionList = showData.sDistortion.split(numberVectorRx, Qt::SkipEmptyParts);
    for (int i = 0; i < sDistortionList.size(); i++)
    {
        if (!numberRx.exactMatch(sDistortionList[i].trimmed())) {
            RegExpMap["Distortion"] = false;
            break;
        }
    }
    
    for (auto it = RegExpMap.begin(); it != RegExpMap.end(); it++)
    {
        if (it->second == false) {
            QMessageBox::critical(this, QString("Error"), QString("The value of %1 is illegal").arg(it->first));
            return false;
        }
    }
    return true;
}

void configuration::Slot_ConfirmBtn_clicked() {
    //判断信号发送者，从对应的界面读取数据，检查无误后更新相机参数
    QObject* pSender = sender();
    if (Q_NULLPTR != pSender) {
        if (pSender->objectName() == "btn_Confirm_cam0") {
            m_pShowPara->cam0ShowPara->sExtrinsicTBC = ui.textEdit_TBS_cam0->toPlainText();
            m_pShowPara->cam0ShowPara->sRate = ui.lineEdit_rate_cam0->text();
            m_pShowPara->cam0ShowPara->sResolution = ui.lineEdit_resolution_cam0->text();
            m_pShowPara->cam0ShowPara->sCameraModel = ui.lineEdit_camera_model_cam0->text();
            m_pShowPara->cam0ShowPara->sFu = ui.lineEdit_fu_cam0->text();
            m_pShowPara->cam0ShowPara->sFv = ui.lineEdit_fv_cam0->text();
            m_pShowPara->cam0ShowPara->sCu = ui.lineEdit_cu_cam0->text();
            m_pShowPara->cam0ShowPara->sCv = ui.lineEdit_cv_cam0->text();
            m_pShowPara->cam0ShowPara->sDistortionModel = ui.lineEdit_distortion_model_cam0->text();
            m_pShowPara->cam0ShowPara->sDistortion = ui.textEdit_coefficients_cam0->toPlainText();
            if (!CheckShowDataExp(*m_pShowPara->cam0ShowPara)) {
                bCam0Saved = false;
                emit ParaAccepted(false);
                return;
            }
            if (!GetCamParaFromShow(*m_pShowPara->cam0ShowPara, *m_pCameraPara->cam0Para)) {
                bCam0Saved = false;
                emit ParaAccepted(false);
                return;
            }
            bCam0Saved = true;
            QMessageBox::information(this, QString("Information"), QString("Saved successfully"));
        }
        else if (pSender->objectName() == "btn_Confirm_cam1") {
            m_pShowPara->cam1ShowPara->sExtrinsicTBC = ui.textEdit_TBS_cam1->toPlainText();
            m_pShowPara->cam1ShowPara->sRate = ui.lineEdit_rate_cam1->text();
            m_pShowPara->cam1ShowPara->sResolution = ui.lineEdit_resolution_cam1->text();
            m_pShowPara->cam1ShowPara->sCameraModel = ui.lineEdit_camera_model_cam1->text();
            m_pShowPara->cam1ShowPara->sFu = ui.lineEdit_fu_cam1->text();
            m_pShowPara->cam1ShowPara->sFv = ui.lineEdit_fv_cam1->text();
            m_pShowPara->cam1ShowPara->sCu = ui.lineEdit_cu_cam1->text();
            m_pShowPara->cam1ShowPara->sCv = ui.lineEdit_cv_cam1->text();
            m_pShowPara->cam1ShowPara->sDistortionModel = ui.lineEdit_distortion_model_cam1->text();
            m_pShowPara->cam1ShowPara->sDistortion = ui.textEdit_coefficients_cam1->toPlainText();
            if (!CheckShowDataExp(*m_pShowPara->cam1ShowPara)) {
                bCam1Saved = false;
                emit ParaAccepted(false);
                return;
            }
            if (!GetCamParaFromShow(*m_pShowPara->cam1ShowPara, *m_pCameraPara->cam1Para)) {
                bCam1Saved = false;
                emit ParaAccepted(false);
                return;
            }
            bCam1Saved = true;
            QMessageBox::information(this, QString("Information"), QString("Saved successfully"));
        }
    }
    //cam0和cam1均加载过配置，求出T01
    if (bCam0Saved && bCam1Saved) {
        m_pCameraPara->extrinsicT10 = m_pCameraPara->cam1Para->extrinsicTBC.inv() * (m_pCameraPara->cam0Para->extrinsicTBC);
        std::cout << "m_pCameraPara->extrinsicT10: " << std::endl << m_pCameraPara->extrinsicT10 << std::endl;
        if (m_pCameraPara->extrinsicT10.at<double>(0, 3) >= 0) {
            QMessageBox::critical(this, QString("Warning"), QString("The T10 is illegal"));
            emit ParaAccepted(false);
            return;
        }
        emit ParaAccepted(true);
    }
}

void configuration::Slot_LoadFromFileBtn_clicked() {
    //从文件加载相机参数，根据信号发送者将yaml参数转化为显示参数
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Open Yaml", ".", "Yaml Files(*.yaml)");
    if (!fileName.isEmpty())
    {
        yamlPara camParaOrigin;
        //加载yaml文件
        try {
            YAML::Node root = YAML::LoadFile(fileName.toStdString());
            YAML::Node extrinsics = root["T_BS"];
            camParaOrigin.extrinsicTBC = extrinsics["data"].as<decltype(camParaOrigin.extrinsicTBC)>();
            camParaOrigin.nRate = root["rate_hz"].as<decltype(camParaOrigin.nRate)>();
            camParaOrigin.vResolution = root["resolution"].as<decltype(camParaOrigin.vResolution)>();
            camParaOrigin.sCameraModel = root["camera_model"].as<decltype(camParaOrigin.sCameraModel)>();
            camParaOrigin.intrinsic = root["intrinsics"].as<decltype(camParaOrigin.intrinsic)>();
            camParaOrigin.sDistortionModel = root["distortion_model"].as<decltype(camParaOrigin.sDistortionModel)>();
            camParaOrigin.vDistortion = root["distortion_coefficients"].as<decltype(camParaOrigin.vDistortion)>();
        }
        catch (exception e) {
            QMessageBox::critical(Q_NULLPTR, QString("Error"), QString("Failed when loading data from the yaml file<br>\
            Error Code: %1").arg(e.what()));
            return;
        }

        QObject* pSender = sender();
        if (pSender != Q_NULLPTR) {
            if (pSender->objectName() == "btn_LoadFromFile_cam0") {
                if (!m_pCameraPara->cam0Para) {
                    m_pCameraPara->cam0Para = new singleCamPara;
                }
                singleCamShowPara camParaShow;
                if (!GetShowParaFromYaml(camParaOrigin, camParaShow)) {
                    return;
                }
                ui.textEdit_TBS_cam0->setText(camParaShow.sExtrinsicTBC);
                ui.lineEdit_rate_cam0->setText(camParaShow.sRate);
                ui.lineEdit_resolution_cam0->setText(camParaShow.sResolution);
                ui.lineEdit_camera_model_cam0->setText(camParaShow.sCameraModel);
                ui.lineEdit_fu_cam0->setText(camParaShow.sFu);
                ui.lineEdit_fv_cam0->setText(camParaShow.sFv);
                ui.lineEdit_cu_cam0->setText(camParaShow.sCu);
                ui.lineEdit_cv_cam0->setText(camParaShow.sCv);
                ui.lineEdit_distortion_model_cam0->setText(camParaShow.sDistortionModel);
                ui.textEdit_coefficients_cam0->setText(camParaShow.sDistortion);
            }
            else if (pSender->objectName() == "btn_LoadFromFile_cam1") {
                if (!m_pCameraPara->cam1Para) {
                    m_pCameraPara->cam1Para = new singleCamPara;
                }
                singleCamShowPara camParaShow;
                if (!GetShowParaFromYaml(camParaOrigin, camParaShow)) {
                    return;
                }
                ui.textEdit_TBS_cam1->setText(camParaShow.sExtrinsicTBC);
                ui.lineEdit_rate_cam1->setText(camParaShow.sRate);
                ui.lineEdit_resolution_cam1->setText(camParaShow.sResolution);
                ui.lineEdit_camera_model_cam1->setText(camParaShow.sCameraModel);
                ui.lineEdit_fu_cam1->setText(camParaShow.sFu);
                ui.lineEdit_fv_cam1->setText(camParaShow.sFv);
                ui.lineEdit_cu_cam1->setText(camParaShow.sCu);
                ui.lineEdit_cv_cam1->setText(camParaShow.sCv);
                ui.lineEdit_distortion_model_cam1->setText(camParaShow.sDistortionModel);
                ui.textEdit_coefficients_cam1->setText(camParaShow.sDistortion);
            }
        }
    }
}


void configuration::GetCamParaFromYaml(yamlPara yamlData, singleCamPara& camData)
{
    //外参
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            camData.extrinsicTBC.at<double>(i, j) = yamlData.extrinsicTBC[i * 4 + j];
        }
    }
    //采样频率
    camData.nRate = yamlData.nRate;
    //分辨率
    camData.vResolution = yamlData.vResolution;
    //相机模型
    camData.sCameraModel = yamlData.sCameraModel;
    //内参
    camData.intrinsic.at<double>(0, 0) = yamlData.intrinsic[0];
    camData.intrinsic.at<double>(1, 1) = yamlData.intrinsic[1];
    camData.intrinsic.at<double>(0, 2) = yamlData.intrinsic[2];
    camData.intrinsic.at<double>(1, 2) = yamlData.intrinsic[3];
    camData.intrinsic.at<double>(2, 2) = 1.0;


    //畸变模型
    camData.sDistortionModel = yamlData.sDistortionModel;
    //畸变系数
    for (int i = 0; i < 4; i++)
    {
        camData.distortionCoefficient.at<float>(0, i) = yamlData.vDistortion[i];
    }
}

bool configuration::GetShowParaFromYaml(yamlPara yamlData, singleCamShowPara& showData) {
    //外参
    if (showData.sExtrinsicTBC.size() != 0) {
        showData.sExtrinsicTBC.clear();
    }
    //若为变换矩阵
    if (16 == yamlData.extrinsicTBC.size()) {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (j != 3) {
                    showData.sExtrinsicTBC.append(QString::number(yamlData.extrinsicTBC[4 * i + j], 'f', 4)).append(',');
                }
                else {
                    showData.sExtrinsicTBC.append(QString::number(yamlData.extrinsicTBC[4 * i + j], 'f', 4));
                }
            }
            showData.sExtrinsicTBC.append("\n");
        }
    }
    else if(7 == yamlData.extrinsicTBC.size()) {
        for (int i = 0; i < 7; i++)
        {
            if (i != 6) {
                showData.sExtrinsicTBC.append(QString::number(yamlData.extrinsicTBC[i], 'f', 4)).append(',');
            }
            else {
                showData.sExtrinsicTBC.append(QString::number(yamlData.extrinsicTBC[i], 'f', 4));
            }
            if (i == 2) {
                showData.sExtrinsicTBC.append("\n");
            }
        }
    }
    else {
        QMessageBox::critical(Q_NULLPTR, QString("Error"), QString("The dimension of T_BS is illegal"));
        return false;
    }
    
    //采样频率
    showData.sRate = QString("%1").arg(yamlData.nRate);
    //分辨率
    showData.sResolution = QString("%1,%2").arg(yamlData.vResolution[0]).arg(yamlData.vResolution[1]);
    //相机模型
    showData.sCameraModel = QString().fromStdString(yamlData.sCameraModel);
    //内参
    showData.sFu = QString::number(yamlData.intrinsic[0], 'f', 4);
    showData.sFv = QString::number(yamlData.intrinsic[1], 'f', 4);
    showData.sCu = QString::number(yamlData.intrinsic[2], 'f', 4);
    showData.sCv = QString::number(yamlData.intrinsic[3], 'f', 4);
    //畸变模型
    showData.sDistortionModel = QString().fromStdString(yamlData.sDistortionModel);
    //畸变系数
    if (showData.sDistortion.size() != 0) {
        showData.sDistortion.clear();
    }
    for (int i = 0; i < yamlData.vDistortion.size(); i++)
    {
        if (i != yamlData.vDistortion.size() - 1) {
            showData.sDistortion.append(QString::number(yamlData.vDistortion[i], 'f', 4)).append(',');
        }
        else {
            showData.sDistortion.append(QString::number(yamlData.vDistortion[i], 'f', 4));
        }
        if (i % 2 == 1 && i != i != yamlData.vDistortion.size() - 1) {
            showData.sDistortion.append("\n");
        }
    }
    return true;
}

bool configuration::GetCamParaFromShow(singleCamShowPara showData, singleCamPara& camData)
{
    //外参
    QRegExp numberVectorRx(",|,\\s+|\\s+");
    QStringList sExtrinsicTBCList = showData.sExtrinsicTBC.split(numberVectorRx, Qt::SkipEmptyParts);
    if (sExtrinsicTBCList.size() != 16 && sExtrinsicTBCList.size() != 7) {
        QMessageBox::critical(Q_NULLPTR, QString("Error"), QString(
            "The dimension of TBC is illegal, please input a transformation matrix(4*4)\
            or a translation vector with a quaternion(1*7 in total)"));
        return false;
    }
    //若为变换矩阵
    if (sExtrinsicTBCList.size() == 16) {
        camData.extrinsicTBC = cv::Mat::zeros(4, 4, CV_64F);
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                camData.extrinsicTBC.at<double>(i, j) = sExtrinsicTBCList[4 * i + j].toFloat();
            }
        }
    }
    //若为平移向量+四元数
    else if (sExtrinsicTBCList.size() == 7) {
        QMessageBox::information(Q_NULLPTR, QString("Information"), QString("Please make sure the sequence of quaternion is xyzw"));
        QStringList sTranslation(sExtrinsicTBCList.begin(), sExtrinsicTBCList.begin() + 3);
        QStringList sQuaternion(sExtrinsicTBCList.begin() + 3, sExtrinsicTBCList.end());
        //平移
        Eigen::Vector3d translation;
        for (int i = 0; i < 3; i++)
        {
            translation[i] = sTranslation[i].toFloat();
        }
        //四元数
        Eigen::Vector4d quaternion_vec;
        //wxyz
        for (int i = 0; i < 4; i++)
        {
            quaternion_vec[i] = sQuaternion[i].toFloat();
        }
        Eigen::Quaternion<double> quaternion(quaternion_vec);
        //检查四元数模长是否为1
        double norm = quaternion.norm();
        if (qAbs(quaternion.norm() - 1) > 1e-2) {
            QMessageBox::critical(Q_NULLPTR, QString("Error"), QString("The norm of quaternion is not equal to 1"));
            return false;
        }
        Eigen::Isometry3d extrinsicTBC = Eigen::Isometry3d::Identity();
        extrinsicTBC.rotate(quaternion);
        extrinsicTBC.pretranslate(translation);
        cv::eigen2cv(extrinsicTBC.matrix(), camData.extrinsicTBC);

    }
    //检查旋转矩阵是否为正交单位阵
    cv::Mat rotationMat = camData.extrinsicTBC(cv::Rect(0, 0, 3, 3));
    //检查行列式的值
    if (qAbs(cv::determinant(rotationMat) - 1) >= 1e-2) {
        QMessageBox::critical(Q_NULLPTR, QString("Error"), QString("The determinant of RBC is not equal to 1"));
        return false;
    }
    //检查是否正交
    cv::Mat rotationMat_transposition = rotationMat.t();
    if (!IsIdentityMatrix(rotationMat * rotationMat_transposition)) {
        QMessageBox::critical(Q_NULLPTR, QString("Error"), QString("The RBC is not a orthogonal matrix"));
        return false;
    }
    //检查最后一行是否为0001
    double lastRowValue[4] = { 0., 0., 0., 1. };
    for (int i = 0; i < 4; i++)
    {
        if (fabs(camData.extrinsicTBC.at<double>(3, i) - lastRowValue[i]) > 1e-2) {
            QMessageBox::critical(Q_NULLPTR, QString("Error"), QString("The last row of TBC is wrong"));
            return false;
        }
    }

    //采样频率
    camData.nRate = showData.sRate.toInt();
    if (camData.nRate <= 0) {
        QMessageBox::critical(Q_NULLPTR, QString("Error"), QString("The value of rate is illegal"));
        return false;
    }

    //分辨率
    QStringList sResolutionList = showData.sResolution.split(numberVectorRx, Qt::SkipEmptyParts);
    if (sResolutionList.size() != 2) {
        QMessageBox::critical(Q_NULLPTR, QString("Error"), QString("The dimension of resolution is illegal"));
        return false;
    }
    if (sResolutionList[0].toInt() <= 0 || sResolutionList[1].toInt() <= 0) {
        QMessageBox::critical(Q_NULLPTR, QString("Error"), QString("The value of resolution is illegal"));
        return false;
    }
    if (camData.vResolution.size() != 0) {
        camData.vResolution.clear();
    }
    camData.vResolution.push_back(sResolutionList[0].toInt());
    camData.vResolution.push_back(sResolutionList[1].toInt());

    //相机模型
    camData.sCameraModel = showData.sCameraModel.toStdString();

    //内参
    camData.intrinsic = cv::Mat::zeros(3, 3, CV_64F);
    camData.intrinsic.at<double>(0, 0) = showData.sFu.toFloat();
    camData.intrinsic.at<double>(1, 1) = showData.sFv.toFloat();
    camData.intrinsic.at<double>(0, 2) = showData.sCu.toFloat();
    camData.intrinsic.at<double>(1, 2) = showData.sCv.toFloat();
    camData.intrinsic.at<double>(2, 2) = 1.0;
    if (camData.intrinsic.at<double>(0, 0) <= 0 || 
        camData.intrinsic.at<double>(1, 1) <= 0 || 
        camData.intrinsic.at<double>(0, 2) <= 0 ||
        camData.intrinsic.at<double>(1, 2) <= 0) {
        QMessageBox::critical(Q_NULLPTR, QString("Error"), QString("The value of insrinsic is illegal"));
        return false;
    }

    //畸变模型
    camData.sDistortionModel = showData.sDistortionModel.toStdString();

    //畸变系数
    QStringList sDistortionList = showData.sDistortion.split(numberVectorRx, Qt::SkipEmptyParts);
    if (sDistortionList.size() < 4) {
        QMessageBox::critical(Q_NULLPTR, QString("Error"), QString("The dimension of distortion vector is not illegal"));
        return false;
    }
    cv::Mat distortionCoefficient = cv::Mat::zeros(sDistortionList.size(), 1, CV_64F);
    for (int i = 0; i < sDistortionList.size(); i++)
    {
        camData.distortionCoefficient.at<double>(0, i) = sDistortionList[i].toFloat();
    }

    return true;
}

void configuration::GetCalibShowParaFromCam(cameraPara camData, showPara& showData)
{
    //cam0
    ConvertMatToString(camData.cam0Para->correctionR, showData.cam0ShowPara->sCorrectionR);
    ConvertMatToString(camData.cam0Para->projectionMatrix, showData.cam0ShowPara->sProjectionMatrix);
    //cam1
    ConvertMatToString(camData.cam1Para->correctionR, showData.cam1ShowPara->sCorrectionR);
    ConvertMatToString(camData.cam1Para->projectionMatrix, showData.cam1ShowPara->sProjectionMatrix);
    //T10
    ConvertMatToString(camData.extrinsicT10, showData.sT10);
    //Q
    ConvertMatToString(camData.Q, showData.sQ);
}

void configuration::ConvertMatToString(cv::Mat mat, QString& str)
{
    str = "";
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            if (j != 3)
                str.append(QString::number(mat.at<double>(i, j), 'f', 3)).append(',');
            else
                str.append(QString::number(mat.at<double>(i, j), 'f', 3));
        }
        str.append("\n");
    }
}
