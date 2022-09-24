/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_Para;
    QPushButton *btn_ModifyPara;
    QTabWidget *tabWidget;
    QWidget *tab_cam0Para_2;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_22;
    QTextEdit *textEdit_TBS_cam0_show;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_23;
    QLineEdit *lineEdit_rate_cam0_show;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_24;
    QLineEdit *lineEdit_resolution_cam0_show;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_25;
    QLineEdit *lineEdit_camera_model_cam0_show;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_26;
    QLineEdit *lineEdit_fu_cam0_show;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_27;
    QLineEdit *lineEdit_fv_cam0_show;
    QHBoxLayout *horizontalLayout_30;
    QLabel *label_28;
    QLineEdit *lineEdit_cu_cam0_show;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_29;
    QLineEdit *lineEdit_cv_cam0_show;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_30;
    QLineEdit *lineEdit_distortion_model_cam0_show;
    QHBoxLayout *horizontalLayout_33;
    QLabel *label_31;
    QTextEdit *textEdit_coefficients_cam0_show;
    QHBoxLayout *horizontalLayout_46;
    QLabel *label_44;
    QTextEdit *textEdit_RCor_cam0_show;
    QHBoxLayout *horizontalLayout_47;
    QLabel *label_45;
    QTextEdit *textEdit_Proj_cam0_show;
    QWidget *tab_cam1Para_2;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_34;
    QLabel *label_32;
    QTextEdit *textEdit_TBS_cam1_show;
    QHBoxLayout *horizontalLayout_35;
    QLabel *label_33;
    QLineEdit *lineEdit_rate_cam1_show;
    QHBoxLayout *horizontalLayout_36;
    QLabel *label_34;
    QLineEdit *lineEdit_resolution_cam1_show;
    QHBoxLayout *horizontalLayout_37;
    QLabel *label_35;
    QLineEdit *lineEdit_camera_model_cam1_show;
    QHBoxLayout *horizontalLayout_38;
    QLabel *label_36;
    QLineEdit *lineEdit_fu_cam1_show;
    QHBoxLayout *horizontalLayout_39;
    QLabel *label_37;
    QLineEdit *lineEdit_fv_cam1_show;
    QHBoxLayout *horizontalLayout_40;
    QLabel *label_38;
    QLineEdit *lineEdit_cu_cam1_show;
    QHBoxLayout *horizontalLayout_41;
    QLabel *label_39;
    QLineEdit *lineEdit_cv_cam1_show;
    QHBoxLayout *horizontalLayout_42;
    QLabel *label_40;
    QLineEdit *lineEdit_distortion_model_cam1_show;
    QHBoxLayout *horizontalLayout_43;
    QLabel *label_41;
    QTextEdit *textEdit_coefficients_cam1_show;
    QHBoxLayout *horizontalLayout_44;
    QLabel *label_42;
    QTextEdit *textEdit_RCor_cam1_show;
    QHBoxLayout *horizontalLayout_45;
    QLabel *label_43;
    QTextEdit *textEdit_Proj_cam1_show;
    QWidget *tab_camPara;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_48;
    QLabel *label_46;
    QTextEdit *textEdit_T10_show;
    QHBoxLayout *horizontalLayout_59;
    QLabel *label_57;
    QTextEdit *textEdit_Q_show;
    QGroupBox *groupBox_ImgShow;
    QLabel *ImgLabelLeft;
    QLabel *ImgLabelRight;
    QLabel *ImgLabelFeatureMatch;
    QGroupBox *groupBox_3dViewer;
    QGroupBox *groupBox_Control;
    QTabWidget *tabWidget_2;
    QWidget *tab_SingleMode;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *ControlLayout;
    QHBoxLayout *OpenImgLayout;
    QPushButton *btn_OpenLeftImg;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_OpenRightImg;
    QHBoxLayout *ProcessImgLayout;
    QPushButton *btn_StereoCalib;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_ExtractFeatures;
    QHBoxLayout *ProcessImgLayout_2;
    QPushButton *btn_CalDepth;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_SaveData;
    QHBoxLayout *ProcessImgLayout_3;
    QPushButton *btn_LoadDisparity;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_CalError;
    QWidget *tab_ContinuousMode;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *ProcessImgLayout_4;
    QPushButton *btn_SelectDirLeft;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_SelectDirRight;
    QHBoxLayout *ProcessImgLayout_5;
    QPushButton *btn_AutoStart;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btn_Pause;
    QHBoxLayout *ProcessImgLayout_6;
    QPushButton *btn_NextImg;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btn_Reset;
    QHBoxLayout *ProcessImgLayout_7;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_ImgName;
    QGroupBox *groupBox_DisparityImgShow;
    QLabel *ImgLabelLeft_2;
    QLabel *ImgLabelRight_2;
    QLabel *ImgLabelDisparity;
    QLabel *label_ImgName_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(2351, 1204);
        MainWindow->setMinimumSize(QSize(300, 300));
        MainWindow->setMaximumSize(QSize(10000, 10000));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(300, 300));
        centralWidget->setMaximumSize(QSize(10000, 10000));
        groupBox_Para = new QGroupBox(centralWidget);
        groupBox_Para->setObjectName(QString::fromUtf8("groupBox_Para"));
        groupBox_Para->setGeometry(QRect(2000, 300, 331, 681));
        btn_ModifyPara = new QPushButton(groupBox_Para);
        btn_ModifyPara->setObjectName(QString::fromUtf8("btn_ModifyPara"));
        btn_ModifyPara->setGeometry(QRect(70, 20, 100, 30));
        btn_ModifyPara->setMinimumSize(QSize(100, 30));
        btn_ModifyPara->setMaximumSize(QSize(100, 30));
        tabWidget = new QTabWidget(groupBox_Para);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 60, 291, 601));
        tabWidget->setMinimumSize(QSize(10, 10));
        tabWidget->setMaximumSize(QSize(10000, 10000));
        tab_cam0Para_2 = new QWidget();
        tab_cam0Para_2->setObjectName(QString::fromUtf8("tab_cam0Para_2"));
        verticalLayoutWidget_5 = new QWidget(tab_cam0Para_2);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(7, 5, 271, 561));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 0, 5, 0);
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        horizontalLayout_24->setContentsMargins(0, 10, 0, 10);
        label_22 = new QLabel(verticalLayoutWidget_5);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMinimumSize(QSize(50, 25));
        label_22->setMaximumSize(QSize(50, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_22->setFont(font);
        label_22->setAlignment(Qt::AlignCenter);

        horizontalLayout_24->addWidget(label_22);

        textEdit_TBS_cam0_show = new QTextEdit(verticalLayoutWidget_5);
        textEdit_TBS_cam0_show->setObjectName(QString::fromUtf8("textEdit_TBS_cam0_show"));
        textEdit_TBS_cam0_show->setEnabled(false);
        textEdit_TBS_cam0_show->setMinimumSize(QSize(100, 65));
        textEdit_TBS_cam0_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_24->addWidget(textEdit_TBS_cam0_show);


        verticalLayout_3->addLayout(horizontalLayout_24);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        label_23 = new QLabel(verticalLayoutWidget_5);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMinimumSize(QSize(125, 25));
        label_23->setMaximumSize(QSize(125, 10000));
        label_23->setFont(font);
        label_23->setAlignment(Qt::AlignCenter);

        horizontalLayout_25->addWidget(label_23);

        lineEdit_rate_cam0_show = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_rate_cam0_show->setObjectName(QString::fromUtf8("lineEdit_rate_cam0_show"));
        lineEdit_rate_cam0_show->setEnabled(false);
        lineEdit_rate_cam0_show->setMinimumSize(QSize(100, 25));
        lineEdit_rate_cam0_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_25->addWidget(lineEdit_rate_cam0_show);


        verticalLayout_3->addLayout(horizontalLayout_25);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        label_24 = new QLabel(verticalLayoutWidget_5);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMinimumSize(QSize(125, 25));
        label_24->setMaximumSize(QSize(125, 10000));
        label_24->setFont(font);
        label_24->setAlignment(Qt::AlignCenter);

        horizontalLayout_26->addWidget(label_24);

        lineEdit_resolution_cam0_show = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_resolution_cam0_show->setObjectName(QString::fromUtf8("lineEdit_resolution_cam0_show"));
        lineEdit_resolution_cam0_show->setEnabled(false);
        lineEdit_resolution_cam0_show->setMinimumSize(QSize(100, 25));
        lineEdit_resolution_cam0_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_26->addWidget(lineEdit_resolution_cam0_show);


        verticalLayout_3->addLayout(horizontalLayout_26);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        label_25 = new QLabel(verticalLayoutWidget_5);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setMinimumSize(QSize(125, 25));
        label_25->setMaximumSize(QSize(125, 10000));
        label_25->setFont(font);
        label_25->setAlignment(Qt::AlignCenter);

        horizontalLayout_27->addWidget(label_25);

        lineEdit_camera_model_cam0_show = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_camera_model_cam0_show->setObjectName(QString::fromUtf8("lineEdit_camera_model_cam0_show"));
        lineEdit_camera_model_cam0_show->setEnabled(false);
        lineEdit_camera_model_cam0_show->setMinimumSize(QSize(100, 25));
        lineEdit_camera_model_cam0_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_27->addWidget(lineEdit_camera_model_cam0_show);


        verticalLayout_3->addLayout(horizontalLayout_27);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        label_26 = new QLabel(verticalLayoutWidget_5);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setMinimumSize(QSize(125, 25));
        label_26->setMaximumSize(QSize(125, 10000));
        label_26->setFont(font);
        label_26->setAlignment(Qt::AlignCenter);

        horizontalLayout_28->addWidget(label_26);

        lineEdit_fu_cam0_show = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_fu_cam0_show->setObjectName(QString::fromUtf8("lineEdit_fu_cam0_show"));
        lineEdit_fu_cam0_show->setEnabled(false);
        lineEdit_fu_cam0_show->setMinimumSize(QSize(100, 25));
        lineEdit_fu_cam0_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_28->addWidget(lineEdit_fu_cam0_show);


        verticalLayout_3->addLayout(horizontalLayout_28);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        label_27 = new QLabel(verticalLayoutWidget_5);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setMinimumSize(QSize(125, 25));
        label_27->setMaximumSize(QSize(125, 10000));
        label_27->setFont(font);
        label_27->setAlignment(Qt::AlignCenter);

        horizontalLayout_29->addWidget(label_27);

        lineEdit_fv_cam0_show = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_fv_cam0_show->setObjectName(QString::fromUtf8("lineEdit_fv_cam0_show"));
        lineEdit_fv_cam0_show->setEnabled(false);
        lineEdit_fv_cam0_show->setMinimumSize(QSize(100, 25));
        lineEdit_fv_cam0_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_29->addWidget(lineEdit_fv_cam0_show);


        verticalLayout_3->addLayout(horizontalLayout_29);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        label_28 = new QLabel(verticalLayoutWidget_5);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setMinimumSize(QSize(125, 25));
        label_28->setMaximumSize(QSize(125, 10000));
        label_28->setFont(font);
        label_28->setAlignment(Qt::AlignCenter);

        horizontalLayout_30->addWidget(label_28);

        lineEdit_cu_cam0_show = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_cu_cam0_show->setObjectName(QString::fromUtf8("lineEdit_cu_cam0_show"));
        lineEdit_cu_cam0_show->setEnabled(false);
        lineEdit_cu_cam0_show->setMinimumSize(QSize(100, 25));
        lineEdit_cu_cam0_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_30->addWidget(lineEdit_cu_cam0_show);


        verticalLayout_3->addLayout(horizontalLayout_30);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        label_29 = new QLabel(verticalLayoutWidget_5);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setMinimumSize(QSize(125, 25));
        label_29->setMaximumSize(QSize(125, 10000));
        label_29->setFont(font);
        label_29->setAlignment(Qt::AlignCenter);

        horizontalLayout_31->addWidget(label_29);

        lineEdit_cv_cam0_show = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_cv_cam0_show->setObjectName(QString::fromUtf8("lineEdit_cv_cam0_show"));
        lineEdit_cv_cam0_show->setEnabled(false);
        lineEdit_cv_cam0_show->setMinimumSize(QSize(100, 25));
        lineEdit_cv_cam0_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_31->addWidget(lineEdit_cv_cam0_show);


        verticalLayout_3->addLayout(horizontalLayout_31);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        label_30 = new QLabel(verticalLayoutWidget_5);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setMinimumSize(QSize(125, 25));
        label_30->setMaximumSize(QSize(125, 10000));
        label_30->setFont(font);
        label_30->setAlignment(Qt::AlignCenter);

        horizontalLayout_32->addWidget(label_30);

        lineEdit_distortion_model_cam0_show = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_distortion_model_cam0_show->setObjectName(QString::fromUtf8("lineEdit_distortion_model_cam0_show"));
        lineEdit_distortion_model_cam0_show->setEnabled(false);
        lineEdit_distortion_model_cam0_show->setMinimumSize(QSize(100, 25));
        lineEdit_distortion_model_cam0_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_32->addWidget(lineEdit_distortion_model_cam0_show);


        verticalLayout_3->addLayout(horizontalLayout_32);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        label_31 = new QLabel(verticalLayoutWidget_5);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setMinimumSize(QSize(125, 25));
        label_31->setMaximumSize(QSize(125, 10000));
        label_31->setFont(font);
        label_31->setAlignment(Qt::AlignCenter);

        horizontalLayout_33->addWidget(label_31);

        textEdit_coefficients_cam0_show = new QTextEdit(verticalLayoutWidget_5);
        textEdit_coefficients_cam0_show->setObjectName(QString::fromUtf8("textEdit_coefficients_cam0_show"));
        textEdit_coefficients_cam0_show->setEnabled(false);
        textEdit_coefficients_cam0_show->setMinimumSize(QSize(100, 50));
        textEdit_coefficients_cam0_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_33->addWidget(textEdit_coefficients_cam0_show);


        verticalLayout_3->addLayout(horizontalLayout_33);

        horizontalLayout_46 = new QHBoxLayout();
        horizontalLayout_46->setSpacing(6);
        horizontalLayout_46->setObjectName(QString::fromUtf8("horizontalLayout_46"));
        horizontalLayout_46->setContentsMargins(0, 10, 0, 10);
        label_44 = new QLabel(verticalLayoutWidget_5);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setMinimumSize(QSize(50, 25));
        label_44->setMaximumSize(QSize(50, 25));
        label_44->setFont(font);
        label_44->setAlignment(Qt::AlignCenter);

        horizontalLayout_46->addWidget(label_44);

        textEdit_RCor_cam0_show = new QTextEdit(verticalLayoutWidget_5);
        textEdit_RCor_cam0_show->setObjectName(QString::fromUtf8("textEdit_RCor_cam0_show"));
        textEdit_RCor_cam0_show->setEnabled(false);
        textEdit_RCor_cam0_show->setMinimumSize(QSize(100, 40));
        textEdit_RCor_cam0_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_46->addWidget(textEdit_RCor_cam0_show);


        verticalLayout_3->addLayout(horizontalLayout_46);

        horizontalLayout_47 = new QHBoxLayout();
        horizontalLayout_47->setSpacing(6);
        horizontalLayout_47->setObjectName(QString::fromUtf8("horizontalLayout_47"));
        horizontalLayout_47->setContentsMargins(0, 10, 0, 10);
        label_45 = new QLabel(verticalLayoutWidget_5);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setMinimumSize(QSize(50, 25));
        label_45->setMaximumSize(QSize(50, 25));
        label_45->setFont(font);
        label_45->setAlignment(Qt::AlignCenter);

        horizontalLayout_47->addWidget(label_45);

        textEdit_Proj_cam0_show = new QTextEdit(verticalLayoutWidget_5);
        textEdit_Proj_cam0_show->setObjectName(QString::fromUtf8("textEdit_Proj_cam0_show"));
        textEdit_Proj_cam0_show->setEnabled(false);
        textEdit_Proj_cam0_show->setMinimumSize(QSize(100, 40));
        textEdit_Proj_cam0_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_47->addWidget(textEdit_Proj_cam0_show);


        verticalLayout_3->addLayout(horizontalLayout_47);

        tabWidget->addTab(tab_cam0Para_2, QString());
        tab_cam1Para_2 = new QWidget();
        tab_cam1Para_2->setObjectName(QString::fromUtf8("tab_cam1Para_2"));
        verticalLayoutWidget_6 = new QWidget(tab_cam1Para_2);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(7, 5, 271, 561));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(5, 0, 5, 0);
        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setSpacing(6);
        horizontalLayout_34->setObjectName(QString::fromUtf8("horizontalLayout_34"));
        horizontalLayout_34->setContentsMargins(0, 10, 0, 10);
        label_32 = new QLabel(verticalLayoutWidget_6);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setMinimumSize(QSize(50, 25));
        label_32->setMaximumSize(QSize(50, 25));
        label_32->setFont(font);
        label_32->setAlignment(Qt::AlignCenter);

        horizontalLayout_34->addWidget(label_32);

        textEdit_TBS_cam1_show = new QTextEdit(verticalLayoutWidget_6);
        textEdit_TBS_cam1_show->setObjectName(QString::fromUtf8("textEdit_TBS_cam1_show"));
        textEdit_TBS_cam1_show->setEnabled(false);
        textEdit_TBS_cam1_show->setMinimumSize(QSize(100, 65));
        textEdit_TBS_cam1_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_34->addWidget(textEdit_TBS_cam1_show);


        verticalLayout_4->addLayout(horizontalLayout_34);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setSpacing(6);
        horizontalLayout_35->setObjectName(QString::fromUtf8("horizontalLayout_35"));
        label_33 = new QLabel(verticalLayoutWidget_6);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setMinimumSize(QSize(125, 25));
        label_33->setMaximumSize(QSize(125, 10000));
        label_33->setFont(font);
        label_33->setAlignment(Qt::AlignCenter);

        horizontalLayout_35->addWidget(label_33);

        lineEdit_rate_cam1_show = new QLineEdit(verticalLayoutWidget_6);
        lineEdit_rate_cam1_show->setObjectName(QString::fromUtf8("lineEdit_rate_cam1_show"));
        lineEdit_rate_cam1_show->setEnabled(false);
        lineEdit_rate_cam1_show->setMinimumSize(QSize(100, 25));
        lineEdit_rate_cam1_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_35->addWidget(lineEdit_rate_cam1_show);


        verticalLayout_4->addLayout(horizontalLayout_35);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setSpacing(6);
        horizontalLayout_36->setObjectName(QString::fromUtf8("horizontalLayout_36"));
        label_34 = new QLabel(verticalLayoutWidget_6);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setMinimumSize(QSize(125, 25));
        label_34->setMaximumSize(QSize(125, 10000));
        label_34->setFont(font);
        label_34->setAlignment(Qt::AlignCenter);

        horizontalLayout_36->addWidget(label_34);

        lineEdit_resolution_cam1_show = new QLineEdit(verticalLayoutWidget_6);
        lineEdit_resolution_cam1_show->setObjectName(QString::fromUtf8("lineEdit_resolution_cam1_show"));
        lineEdit_resolution_cam1_show->setEnabled(false);
        lineEdit_resolution_cam1_show->setMinimumSize(QSize(100, 25));
        lineEdit_resolution_cam1_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_36->addWidget(lineEdit_resolution_cam1_show);


        verticalLayout_4->addLayout(horizontalLayout_36);

        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setSpacing(6);
        horizontalLayout_37->setObjectName(QString::fromUtf8("horizontalLayout_37"));
        label_35 = new QLabel(verticalLayoutWidget_6);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setMinimumSize(QSize(125, 25));
        label_35->setMaximumSize(QSize(125, 10000));
        label_35->setFont(font);
        label_35->setAlignment(Qt::AlignCenter);

        horizontalLayout_37->addWidget(label_35);

        lineEdit_camera_model_cam1_show = new QLineEdit(verticalLayoutWidget_6);
        lineEdit_camera_model_cam1_show->setObjectName(QString::fromUtf8("lineEdit_camera_model_cam1_show"));
        lineEdit_camera_model_cam1_show->setEnabled(false);
        lineEdit_camera_model_cam1_show->setMinimumSize(QSize(100, 25));
        lineEdit_camera_model_cam1_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_37->addWidget(lineEdit_camera_model_cam1_show);


        verticalLayout_4->addLayout(horizontalLayout_37);

        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setSpacing(6);
        horizontalLayout_38->setObjectName(QString::fromUtf8("horizontalLayout_38"));
        label_36 = new QLabel(verticalLayoutWidget_6);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setMinimumSize(QSize(125, 25));
        label_36->setMaximumSize(QSize(125, 10000));
        label_36->setFont(font);
        label_36->setAlignment(Qt::AlignCenter);

        horizontalLayout_38->addWidget(label_36);

        lineEdit_fu_cam1_show = new QLineEdit(verticalLayoutWidget_6);
        lineEdit_fu_cam1_show->setObjectName(QString::fromUtf8("lineEdit_fu_cam1_show"));
        lineEdit_fu_cam1_show->setEnabled(false);
        lineEdit_fu_cam1_show->setMinimumSize(QSize(100, 25));
        lineEdit_fu_cam1_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_38->addWidget(lineEdit_fu_cam1_show);


        verticalLayout_4->addLayout(horizontalLayout_38);

        horizontalLayout_39 = new QHBoxLayout();
        horizontalLayout_39->setSpacing(6);
        horizontalLayout_39->setObjectName(QString::fromUtf8("horizontalLayout_39"));
        label_37 = new QLabel(verticalLayoutWidget_6);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setMinimumSize(QSize(125, 25));
        label_37->setMaximumSize(QSize(125, 10000));
        label_37->setFont(font);
        label_37->setAlignment(Qt::AlignCenter);

        horizontalLayout_39->addWidget(label_37);

        lineEdit_fv_cam1_show = new QLineEdit(verticalLayoutWidget_6);
        lineEdit_fv_cam1_show->setObjectName(QString::fromUtf8("lineEdit_fv_cam1_show"));
        lineEdit_fv_cam1_show->setEnabled(false);
        lineEdit_fv_cam1_show->setMinimumSize(QSize(100, 25));
        lineEdit_fv_cam1_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_39->addWidget(lineEdit_fv_cam1_show);


        verticalLayout_4->addLayout(horizontalLayout_39);

        horizontalLayout_40 = new QHBoxLayout();
        horizontalLayout_40->setSpacing(6);
        horizontalLayout_40->setObjectName(QString::fromUtf8("horizontalLayout_40"));
        label_38 = new QLabel(verticalLayoutWidget_6);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setMinimumSize(QSize(125, 25));
        label_38->setMaximumSize(QSize(125, 10000));
        label_38->setFont(font);
        label_38->setAlignment(Qt::AlignCenter);

        horizontalLayout_40->addWidget(label_38);

        lineEdit_cu_cam1_show = new QLineEdit(verticalLayoutWidget_6);
        lineEdit_cu_cam1_show->setObjectName(QString::fromUtf8("lineEdit_cu_cam1_show"));
        lineEdit_cu_cam1_show->setEnabled(false);
        lineEdit_cu_cam1_show->setMinimumSize(QSize(100, 25));
        lineEdit_cu_cam1_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_40->addWidget(lineEdit_cu_cam1_show);


        verticalLayout_4->addLayout(horizontalLayout_40);

        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setSpacing(6);
        horizontalLayout_41->setObjectName(QString::fromUtf8("horizontalLayout_41"));
        label_39 = new QLabel(verticalLayoutWidget_6);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setMinimumSize(QSize(125, 25));
        label_39->setMaximumSize(QSize(125, 10000));
        label_39->setFont(font);
        label_39->setAlignment(Qt::AlignCenter);

        horizontalLayout_41->addWidget(label_39);

        lineEdit_cv_cam1_show = new QLineEdit(verticalLayoutWidget_6);
        lineEdit_cv_cam1_show->setObjectName(QString::fromUtf8("lineEdit_cv_cam1_show"));
        lineEdit_cv_cam1_show->setEnabled(false);
        lineEdit_cv_cam1_show->setMinimumSize(QSize(100, 25));
        lineEdit_cv_cam1_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_41->addWidget(lineEdit_cv_cam1_show);


        verticalLayout_4->addLayout(horizontalLayout_41);

        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setSpacing(6);
        horizontalLayout_42->setObjectName(QString::fromUtf8("horizontalLayout_42"));
        label_40 = new QLabel(verticalLayoutWidget_6);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setMinimumSize(QSize(125, 25));
        label_40->setMaximumSize(QSize(125, 10000));
        label_40->setFont(font);
        label_40->setAlignment(Qt::AlignCenter);

        horizontalLayout_42->addWidget(label_40);

        lineEdit_distortion_model_cam1_show = new QLineEdit(verticalLayoutWidget_6);
        lineEdit_distortion_model_cam1_show->setObjectName(QString::fromUtf8("lineEdit_distortion_model_cam1_show"));
        lineEdit_distortion_model_cam1_show->setEnabled(false);
        lineEdit_distortion_model_cam1_show->setMinimumSize(QSize(100, 25));
        lineEdit_distortion_model_cam1_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_42->addWidget(lineEdit_distortion_model_cam1_show);


        verticalLayout_4->addLayout(horizontalLayout_42);

        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setSpacing(6);
        horizontalLayout_43->setObjectName(QString::fromUtf8("horizontalLayout_43"));
        label_41 = new QLabel(verticalLayoutWidget_6);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setMinimumSize(QSize(125, 25));
        label_41->setMaximumSize(QSize(125, 10000));
        label_41->setFont(font);
        label_41->setAlignment(Qt::AlignCenter);

        horizontalLayout_43->addWidget(label_41);

        textEdit_coefficients_cam1_show = new QTextEdit(verticalLayoutWidget_6);
        textEdit_coefficients_cam1_show->setObjectName(QString::fromUtf8("textEdit_coefficients_cam1_show"));
        textEdit_coefficients_cam1_show->setEnabled(false);
        textEdit_coefficients_cam1_show->setMinimumSize(QSize(100, 50));
        textEdit_coefficients_cam1_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_43->addWidget(textEdit_coefficients_cam1_show);


        verticalLayout_4->addLayout(horizontalLayout_43);

        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setSpacing(6);
        horizontalLayout_44->setObjectName(QString::fromUtf8("horizontalLayout_44"));
        horizontalLayout_44->setContentsMargins(0, 10, 0, 10);
        label_42 = new QLabel(verticalLayoutWidget_6);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setMinimumSize(QSize(50, 25));
        label_42->setMaximumSize(QSize(50, 25));
        label_42->setFont(font);
        label_42->setAlignment(Qt::AlignCenter);

        horizontalLayout_44->addWidget(label_42);

        textEdit_RCor_cam1_show = new QTextEdit(verticalLayoutWidget_6);
        textEdit_RCor_cam1_show->setObjectName(QString::fromUtf8("textEdit_RCor_cam1_show"));
        textEdit_RCor_cam1_show->setEnabled(false);
        textEdit_RCor_cam1_show->setMinimumSize(QSize(100, 40));
        textEdit_RCor_cam1_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_44->addWidget(textEdit_RCor_cam1_show);


        verticalLayout_4->addLayout(horizontalLayout_44);

        horizontalLayout_45 = new QHBoxLayout();
        horizontalLayout_45->setSpacing(6);
        horizontalLayout_45->setObjectName(QString::fromUtf8("horizontalLayout_45"));
        horizontalLayout_45->setContentsMargins(0, 10, 0, 10);
        label_43 = new QLabel(verticalLayoutWidget_6);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setMinimumSize(QSize(50, 25));
        label_43->setMaximumSize(QSize(50, 25));
        label_43->setFont(font);
        label_43->setAlignment(Qt::AlignCenter);

        horizontalLayout_45->addWidget(label_43);

        textEdit_Proj_cam1_show = new QTextEdit(verticalLayoutWidget_6);
        textEdit_Proj_cam1_show->setObjectName(QString::fromUtf8("textEdit_Proj_cam1_show"));
        textEdit_Proj_cam1_show->setEnabled(false);
        textEdit_Proj_cam1_show->setMinimumSize(QSize(100, 40));
        textEdit_Proj_cam1_show->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_45->addWidget(textEdit_Proj_cam1_show);


        verticalLayout_4->addLayout(horizontalLayout_45);

        tabWidget->addTab(tab_cam1Para_2, QString());
        tab_camPara = new QWidget();
        tab_camPara->setObjectName(QString::fromUtf8("tab_camPara"));
        verticalLayoutWidget_7 = new QWidget(tab_camPara);
        verticalLayoutWidget_7->setObjectName(QString::fromUtf8("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(10, 10, 261, 171));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(5, 0, 5, 0);
        horizontalLayout_48 = new QHBoxLayout();
        horizontalLayout_48->setSpacing(6);
        horizontalLayout_48->setObjectName(QString::fromUtf8("horizontalLayout_48"));
        horizontalLayout_48->setContentsMargins(0, 10, 0, 10);
        label_46 = new QLabel(verticalLayoutWidget_7);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setMinimumSize(QSize(40, 25));
        label_46->setMaximumSize(QSize(40, 25));
        label_46->setFont(font);
        label_46->setAlignment(Qt::AlignCenter);

        horizontalLayout_48->addWidget(label_46);

        textEdit_T10_show = new QTextEdit(verticalLayoutWidget_7);
        textEdit_T10_show->setObjectName(QString::fromUtf8("textEdit_T10_show"));
        textEdit_T10_show->setEnabled(false);
        textEdit_T10_show->setMinimumSize(QSize(100, 60));
        textEdit_T10_show->setMaximumSize(QSize(10000, 60));

        horizontalLayout_48->addWidget(textEdit_T10_show);


        verticalLayout_5->addLayout(horizontalLayout_48);

        horizontalLayout_59 = new QHBoxLayout();
        horizontalLayout_59->setSpacing(6);
        horizontalLayout_59->setObjectName(QString::fromUtf8("horizontalLayout_59"));
        horizontalLayout_59->setContentsMargins(0, 10, 0, 10);
        label_57 = new QLabel(verticalLayoutWidget_7);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setMinimumSize(QSize(40, 25));
        label_57->setMaximumSize(QSize(50, 25));
        label_57->setFont(font);
        label_57->setAlignment(Qt::AlignCenter);

        horizontalLayout_59->addWidget(label_57);

        textEdit_Q_show = new QTextEdit(verticalLayoutWidget_7);
        textEdit_Q_show->setObjectName(QString::fromUtf8("textEdit_Q_show"));
        textEdit_Q_show->setEnabled(false);
        textEdit_Q_show->setMinimumSize(QSize(100, 60));
        textEdit_Q_show->setMaximumSize(QSize(10000, 60));

        horizontalLayout_59->addWidget(textEdit_Q_show);


        verticalLayout_5->addLayout(horizontalLayout_59);

        tabWidget->addTab(tab_camPara, QString());
        tabWidget->raise();
        btn_ModifyPara->raise();
        groupBox_ImgShow = new QGroupBox(centralWidget);
        groupBox_ImgShow->setObjectName(QString::fromUtf8("groupBox_ImgShow"));
        groupBox_ImgShow->setGeometry(QRect(20, 10, 1960, 580));
        ImgLabelLeft = new QLabel(groupBox_ImgShow);
        ImgLabelLeft->setObjectName(QString::fromUtf8("ImgLabelLeft"));
        ImgLabelLeft->setEnabled(true);
        ImgLabelLeft->setGeometry(QRect(20, 20, 960, 540));
        ImgLabelLeft->setMinimumSize(QSize(0, 0));
        ImgLabelLeft->setMaximumSize(QSize(10000, 10000));
        ImgLabelRight = new QLabel(groupBox_ImgShow);
        ImgLabelRight->setObjectName(QString::fromUtf8("ImgLabelRight"));
        ImgLabelRight->setGeometry(QRect(980, 20, 960, 540));
        ImgLabelRight->setMinimumSize(QSize(0, 0));
        ImgLabelRight->setMaximumSize(QSize(10000, 10000));
        ImgLabelFeatureMatch = new QLabel(groupBox_ImgShow);
        ImgLabelFeatureMatch->setObjectName(QString::fromUtf8("ImgLabelFeatureMatch"));
        ImgLabelFeatureMatch->setEnabled(true);
        ImgLabelFeatureMatch->setGeometry(QRect(20, 20, 1920, 540));
        ImgLabelFeatureMatch->setMinimumSize(QSize(0, 0));
        ImgLabelFeatureMatch->setMaximumSize(QSize(10000, 10000));
        groupBox_3dViewer = new QGroupBox(centralWidget);
        groupBox_3dViewer->setObjectName(QString::fromUtf8("groupBox_3dViewer"));
        groupBox_3dViewer->setGeometry(QRect(20, 610, 931, 581));
        groupBox_3dViewer->setMinimumSize(QSize(0, 450));
        groupBox_Control = new QGroupBox(centralWidget);
        groupBox_Control->setObjectName(QString::fromUtf8("groupBox_Control"));
        groupBox_Control->setGeometry(QRect(2000, 10, 331, 271));
        tabWidget_2 = new QTabWidget(groupBox_Control);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(20, 20, 295, 231));
        tab_SingleMode = new QWidget();
        tab_SingleMode->setObjectName(QString::fromUtf8("tab_SingleMode"));
        verticalLayoutWidget = new QWidget(tab_SingleMode);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 271, 191));
        ControlLayout = new QVBoxLayout(verticalLayoutWidget);
        ControlLayout->setSpacing(6);
        ControlLayout->setContentsMargins(11, 11, 11, 11);
        ControlLayout->setObjectName(QString::fromUtf8("ControlLayout"));
        ControlLayout->setContentsMargins(5, 0, 5, 0);
        OpenImgLayout = new QHBoxLayout();
        OpenImgLayout->setSpacing(6);
        OpenImgLayout->setObjectName(QString::fromUtf8("OpenImgLayout"));
        OpenImgLayout->setContentsMargins(10, 0, 10, -1);
        btn_OpenLeftImg = new QPushButton(verticalLayoutWidget);
        btn_OpenLeftImg->setObjectName(QString::fromUtf8("btn_OpenLeftImg"));
        btn_OpenLeftImg->setEnabled(true);
        btn_OpenLeftImg->setMinimumSize(QSize(100, 30));
        btn_OpenLeftImg->setMaximumSize(QSize(100, 30));
        QFont font1;
        font1.setPointSize(10);
        btn_OpenLeftImg->setFont(font1);

        OpenImgLayout->addWidget(btn_OpenLeftImg);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        OpenImgLayout->addItem(horizontalSpacer_2);

        btn_OpenRightImg = new QPushButton(verticalLayoutWidget);
        btn_OpenRightImg->setObjectName(QString::fromUtf8("btn_OpenRightImg"));
        btn_OpenRightImg->setEnabled(true);
        btn_OpenRightImg->setMinimumSize(QSize(100, 30));
        btn_OpenRightImg->setFont(font1);

        OpenImgLayout->addWidget(btn_OpenRightImg);


        ControlLayout->addLayout(OpenImgLayout);

        ProcessImgLayout = new QHBoxLayout();
        ProcessImgLayout->setSpacing(6);
        ProcessImgLayout->setObjectName(QString::fromUtf8("ProcessImgLayout"));
        ProcessImgLayout->setContentsMargins(10, -1, 10, -1);
        btn_StereoCalib = new QPushButton(verticalLayoutWidget);
        btn_StereoCalib->setObjectName(QString::fromUtf8("btn_StereoCalib"));
        btn_StereoCalib->setEnabled(false);
        btn_StereoCalib->setMinimumSize(QSize(100, 30));
        btn_StereoCalib->setMaximumSize(QSize(100, 30));
        btn_StereoCalib->setFont(font1);

        ProcessImgLayout->addWidget(btn_StereoCalib);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ProcessImgLayout->addItem(horizontalSpacer_3);

        btn_ExtractFeatures = new QPushButton(verticalLayoutWidget);
        btn_ExtractFeatures->setObjectName(QString::fromUtf8("btn_ExtractFeatures"));
        btn_ExtractFeatures->setEnabled(false);
        btn_ExtractFeatures->setMinimumSize(QSize(100, 30));
        btn_ExtractFeatures->setFont(font1);

        ProcessImgLayout->addWidget(btn_ExtractFeatures);


        ControlLayout->addLayout(ProcessImgLayout);

        ProcessImgLayout_2 = new QHBoxLayout();
        ProcessImgLayout_2->setSpacing(6);
        ProcessImgLayout_2->setObjectName(QString::fromUtf8("ProcessImgLayout_2"));
        ProcessImgLayout_2->setContentsMargins(10, -1, 10, -1);
        btn_CalDepth = new QPushButton(verticalLayoutWidget);
        btn_CalDepth->setObjectName(QString::fromUtf8("btn_CalDepth"));
        btn_CalDepth->setEnabled(false);
        btn_CalDepth->setMinimumSize(QSize(100, 30));
        btn_CalDepth->setMaximumSize(QSize(100, 30));
        btn_CalDepth->setFont(font1);

        ProcessImgLayout_2->addWidget(btn_CalDepth);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ProcessImgLayout_2->addItem(horizontalSpacer_4);

        btn_SaveData = new QPushButton(verticalLayoutWidget);
        btn_SaveData->setObjectName(QString::fromUtf8("btn_SaveData"));
        btn_SaveData->setEnabled(false);
        btn_SaveData->setMinimumSize(QSize(100, 30));
        btn_SaveData->setFont(font1);

        ProcessImgLayout_2->addWidget(btn_SaveData);


        ControlLayout->addLayout(ProcessImgLayout_2);

        ProcessImgLayout_3 = new QHBoxLayout();
        ProcessImgLayout_3->setSpacing(6);
        ProcessImgLayout_3->setObjectName(QString::fromUtf8("ProcessImgLayout_3"));
        ProcessImgLayout_3->setContentsMargins(10, -1, 10, -1);
        btn_LoadDisparity = new QPushButton(verticalLayoutWidget);
        btn_LoadDisparity->setObjectName(QString::fromUtf8("btn_LoadDisparity"));
        btn_LoadDisparity->setEnabled(false);
        btn_LoadDisparity->setMinimumSize(QSize(100, 30));
        btn_LoadDisparity->setMaximumSize(QSize(100, 30));
        btn_LoadDisparity->setFont(font1);

        ProcessImgLayout_3->addWidget(btn_LoadDisparity);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ProcessImgLayout_3->addItem(horizontalSpacer_5);

        btn_CalError = new QPushButton(verticalLayoutWidget);
        btn_CalError->setObjectName(QString::fromUtf8("btn_CalError"));
        btn_CalError->setEnabled(false);
        btn_CalError->setMinimumSize(QSize(100, 30));
        btn_CalError->setFont(font1);

        ProcessImgLayout_3->addWidget(btn_CalError);


        ControlLayout->addLayout(ProcessImgLayout_3);

        tabWidget_2->addTab(tab_SingleMode, QString());
        tab_ContinuousMode = new QWidget();
        tab_ContinuousMode->setObjectName(QString::fromUtf8("tab_ContinuousMode"));
        verticalLayoutWidget_2 = new QWidget(tab_ContinuousMode);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 271, 191));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 0, 5, 0);
        ProcessImgLayout_4 = new QHBoxLayout();
        ProcessImgLayout_4->setSpacing(6);
        ProcessImgLayout_4->setObjectName(QString::fromUtf8("ProcessImgLayout_4"));
        ProcessImgLayout_4->setContentsMargins(10, -1, 10, -1);
        btn_SelectDirLeft = new QPushButton(verticalLayoutWidget_2);
        btn_SelectDirLeft->setObjectName(QString::fromUtf8("btn_SelectDirLeft"));
        btn_SelectDirLeft->setEnabled(true);
        btn_SelectDirLeft->setMinimumSize(QSize(100, 30));
        btn_SelectDirLeft->setMaximumSize(QSize(100, 30));
        btn_SelectDirLeft->setFont(font1);

        ProcessImgLayout_4->addWidget(btn_SelectDirLeft);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ProcessImgLayout_4->addItem(horizontalSpacer_6);

        btn_SelectDirRight = new QPushButton(verticalLayoutWidget_2);
        btn_SelectDirRight->setObjectName(QString::fromUtf8("btn_SelectDirRight"));
        btn_SelectDirRight->setEnabled(true);
        btn_SelectDirRight->setMinimumSize(QSize(100, 30));
        btn_SelectDirRight->setFont(font1);

        ProcessImgLayout_4->addWidget(btn_SelectDirRight);


        verticalLayout->addLayout(ProcessImgLayout_4);

        ProcessImgLayout_5 = new QHBoxLayout();
        ProcessImgLayout_5->setSpacing(6);
        ProcessImgLayout_5->setObjectName(QString::fromUtf8("ProcessImgLayout_5"));
        ProcessImgLayout_5->setContentsMargins(10, -1, 10, -1);
        btn_AutoStart = new QPushButton(verticalLayoutWidget_2);
        btn_AutoStart->setObjectName(QString::fromUtf8("btn_AutoStart"));
        btn_AutoStart->setEnabled(false);
        btn_AutoStart->setMinimumSize(QSize(100, 30));
        btn_AutoStart->setMaximumSize(QSize(100, 30));
        btn_AutoStart->setFont(font1);

        ProcessImgLayout_5->addWidget(btn_AutoStart);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ProcessImgLayout_5->addItem(horizontalSpacer_7);

        btn_Pause = new QPushButton(verticalLayoutWidget_2);
        btn_Pause->setObjectName(QString::fromUtf8("btn_Pause"));
        btn_Pause->setEnabled(false);
        btn_Pause->setMinimumSize(QSize(100, 30));
        btn_Pause->setFont(font1);

        ProcessImgLayout_5->addWidget(btn_Pause);


        verticalLayout->addLayout(ProcessImgLayout_5);

        ProcessImgLayout_6 = new QHBoxLayout();
        ProcessImgLayout_6->setSpacing(6);
        ProcessImgLayout_6->setObjectName(QString::fromUtf8("ProcessImgLayout_6"));
        ProcessImgLayout_6->setContentsMargins(10, -1, 10, -1);
        btn_NextImg = new QPushButton(verticalLayoutWidget_2);
        btn_NextImg->setObjectName(QString::fromUtf8("btn_NextImg"));
        btn_NextImg->setEnabled(false);
        btn_NextImg->setMinimumSize(QSize(100, 30));
        btn_NextImg->setMaximumSize(QSize(100, 30));
        btn_NextImg->setFont(font1);

        ProcessImgLayout_6->addWidget(btn_NextImg);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ProcessImgLayout_6->addItem(horizontalSpacer_8);

        btn_Reset = new QPushButton(verticalLayoutWidget_2);
        btn_Reset->setObjectName(QString::fromUtf8("btn_Reset"));
        btn_Reset->setEnabled(false);
        btn_Reset->setMinimumSize(QSize(100, 30));
        btn_Reset->setFont(font1);

        ProcessImgLayout_6->addWidget(btn_Reset);


        verticalLayout->addLayout(ProcessImgLayout_6);

        ProcessImgLayout_7 = new QHBoxLayout();
        ProcessImgLayout_7->setSpacing(6);
        ProcessImgLayout_7->setObjectName(QString::fromUtf8("ProcessImgLayout_7"));
        ProcessImgLayout_7->setContentsMargins(10, -1, 10, -1);
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 30));
        label->setMaximumSize(QSize(16777215, 30));

        ProcessImgLayout_7->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ProcessImgLayout_7->addItem(horizontalSpacer);

        label_ImgName = new QLabel(verticalLayoutWidget_2);
        label_ImgName->setObjectName(QString::fromUtf8("label_ImgName"));
        label_ImgName->setMinimumSize(QSize(0, 30));
        label_ImgName->setMaximumSize(QSize(16777215, 30));
        label_ImgName->setFont(font1);
        label_ImgName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        ProcessImgLayout_7->addWidget(label_ImgName);


        verticalLayout->addLayout(ProcessImgLayout_7);

        tabWidget_2->addTab(tab_ContinuousMode, QString());
        groupBox_DisparityImgShow = new QGroupBox(centralWidget);
        groupBox_DisparityImgShow->setObjectName(QString::fromUtf8("groupBox_DisparityImgShow"));
        groupBox_DisparityImgShow->setGeometry(QRect(980, 610, 1000, 580));
        ImgLabelLeft_2 = new QLabel(groupBox_DisparityImgShow);
        ImgLabelLeft_2->setObjectName(QString::fromUtf8("ImgLabelLeft_2"));
        ImgLabelLeft_2->setEnabled(true);
        ImgLabelLeft_2->setGeometry(QRect(20, 20, 300, 300));
        ImgLabelLeft_2->setMinimumSize(QSize(0, 0));
        ImgLabelLeft_2->setMaximumSize(QSize(10000, 10000));
        ImgLabelRight_2 = new QLabel(groupBox_DisparityImgShow);
        ImgLabelRight_2->setObjectName(QString::fromUtf8("ImgLabelRight_2"));
        ImgLabelRight_2->setGeometry(QRect(320, 20, 300, 300));
        ImgLabelRight_2->setMinimumSize(QSize(0, 0));
        ImgLabelRight_2->setMaximumSize(QSize(10000, 10000));
        ImgLabelDisparity = new QLabel(groupBox_DisparityImgShow);
        ImgLabelDisparity->setObjectName(QString::fromUtf8("ImgLabelDisparity"));
        ImgLabelDisparity->setEnabled(true);
        ImgLabelDisparity->setGeometry(QRect(20, 20, 960, 540));
        ImgLabelDisparity->setMinimumSize(QSize(0, 0));
        ImgLabelDisparity->setMaximumSize(QSize(10000, 10000));
        label_ImgName_2 = new QLabel(groupBox_DisparityImgShow);
        label_ImgName_2->setObjectName(QString::fromUtf8("label_ImgName_2"));
        label_ImgName_2->setGeometry(QRect(480, 310, 154, 25));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_Para->setTitle(QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\351\205\215\347\275\256", nullptr));
        btn_ModifyPara->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\351\205\215\347\275\256", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "TBS", nullptr));
        textEdit_TBS_cam0_show->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "rate_hz", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "resolution", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "camera_model", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "fu", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "fv", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "cu", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "cv", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "distortion_model", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "coefficients", nullptr));
        textEdit_coefficients_cam0_show->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "Rcor", nullptr));
        textEdit_RCor_cam0_show->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "Proj", nullptr));
        textEdit_Proj_cam0_show->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_cam0Para_2), QCoreApplication::translate("MainWindow", "\347\233\270\346\234\2720\345\217\202\346\225\260", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "TBS", nullptr));
        textEdit_TBS_cam1_show->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "rate_hz", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "resolution", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "camera_model", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "fu", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "fv", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "cu", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "cv", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "distortion_model", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "coefficients", nullptr));
        textEdit_coefficients_cam1_show->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "Rcor", nullptr));
        textEdit_RCor_cam1_show->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "Proj", nullptr));
        textEdit_Proj_cam1_show->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_cam1Para_2), QCoreApplication::translate("MainWindow", "\347\233\270\346\234\2721\345\217\202\346\225\260", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "T10", nullptr));
        textEdit_T10_show->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_57->setText(QCoreApplication::translate("MainWindow", "Q", nullptr));
        textEdit_Q_show->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_camPara), QCoreApplication::translate("MainWindow", "\345\244\226\345\217\202", nullptr));
        groupBox_ImgShow->setTitle(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\346\230\276\347\244\272", nullptr));
        ImgLabelLeft->setText(QString());
        ImgLabelRight->setText(QString());
        ImgLabelFeatureMatch->setText(QString());
        groupBox_3dViewer->setTitle(QCoreApplication::translate("MainWindow", "\344\270\211\347\273\264\345\217\257\350\247\206\345\214\226", nullptr));
        groupBox_Control->setTitle(QCoreApplication::translate("MainWindow", "\346\216\247\345\210\266\351\235\242\346\235\277", nullptr));
        btn_OpenLeftImg->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\345\267\246\344\276\247\345\233\276\345\203\217", nullptr));
        btn_OpenRightImg->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\345\217\263\344\276\247\345\233\276\345\203\217", nullptr));
        btn_StereoCalib->setText(QCoreApplication::translate("MainWindow", "\347\253\213\344\275\223\346\240\241\346\255\243", nullptr));
        btn_ExtractFeatures->setText(QCoreApplication::translate("MainWindow", "\347\211\271\345\276\201\346\217\220\345\217\226", nullptr));
        btn_CalDepth->setText(QCoreApplication::translate("MainWindow", "\346\267\261\345\272\246\350\256\241\347\256\227", nullptr));
        btn_SaveData->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        btn_LoadDisparity->setText(QCoreApplication::translate("MainWindow", "\350\275\275\345\205\245\346\267\261\345\272\246", nullptr));
        btn_CalError->setText(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227\350\257\257\345\267\256", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_SingleMode), QCoreApplication::translate("MainWindow", "\345\215\225\345\274\240\346\250\241\345\274\217", nullptr));
        btn_SelectDirLeft->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\345\267\246\344\276\247\346\226\207\344\273\266\345\244\271", nullptr));
        btn_SelectDirRight->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\345\217\263\344\276\247\346\226\207\344\273\266\345\244\271", nullptr));
        btn_AutoStart->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        btn_Pause->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        btn_NextImg->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\345\274\240", nullptr));
        btn_Reset->setText(QCoreApplication::translate("MainWindow", "\351\207\215\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Image Name:", nullptr));
        label_ImgName->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_ContinuousMode), QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221\346\250\241\345\274\217", nullptr));
        groupBox_DisparityImgShow->setTitle(QCoreApplication::translate("MainWindow", "\350\247\206\345\267\256\345\233\276", nullptr));
        ImgLabelLeft_2->setText(QString());
        ImgLabelRight_2->setText(QString());
        ImgLabelDisparity->setText(QString());
        label_ImgName_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
