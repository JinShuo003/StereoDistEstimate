/********************************************************************************
** Form generated from reading UI file 'configuration.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURATION_H
#define UI_CONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_configurationClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_cam0Para;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_23;
    QTextEdit *textEdit_TBS_cam0;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *lineEdit_rate_cam0;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *lineEdit_resolution_cam0;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *lineEdit_camera_model_cam0;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLineEdit *lineEdit_fu_cam0;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QLineEdit *lineEdit_fv_cam0;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_13;
    QLineEdit *lineEdit_cu_cam0;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_11;
    QLineEdit *lineEdit_cv_cam0;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_10;
    QLineEdit *lineEdit_distortion_model_cam0;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QTextEdit *textEdit_coefficients_cam0;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_LoadFromFile_cam0;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_Confirm_cam0;
    QWidget *tab_cam1Para;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_22;
    QTextEdit *textEdit_TBS_cam1;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_12;
    QLineEdit *lineEdit_rate_cam1;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_14;
    QLineEdit *lineEdit_resolution_cam1;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_15;
    QLineEdit *lineEdit_camera_model_cam1;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_16;
    QLineEdit *lineEdit_fu_cam1;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_17;
    QLineEdit *lineEdit_fv_cam1;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_18;
    QLineEdit *lineEdit_cu_cam1;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_19;
    QLineEdit *lineEdit_cv_cam1;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_20;
    QLineEdit *lineEdit_distortion_model_cam1;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_21;
    QTextEdit *textEdit_coefficients_cam1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_LoadFromFile_cam1;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_Confirm_cam1;

    void setupUi(QMainWindow *configurationClass)
    {
        if (configurationClass->objectName().isEmpty())
            configurationClass->setObjectName(QString::fromUtf8("configurationClass"));
        configurationClass->setEnabled(true);
        configurationClass->resize(421, 613);
        centralWidget = new QWidget(configurationClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(10, 10, 401, 591));
        tabWidget->setMinimumSize(QSize(10, 10));
        tabWidget->setMaximumSize(QSize(10000, 10000));
        tab_cam0Para = new QWidget();
        tab_cam0Para->setObjectName(QString::fromUtf8("tab_cam0Para"));
        verticalLayoutWidget_3 = new QWidget(tab_cam0Para);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 10, 371, 541));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 0, 5, 0);
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        label_23 = new QLabel(verticalLayoutWidget_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMinimumSize(QSize(150, 25));
        label_23->setMaximumSize(QSize(10000, 10000));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_23->setFont(font);
        label_23->setAlignment(Qt::AlignCenter);

        horizontalLayout_25->addWidget(label_23);

        textEdit_TBS_cam0 = new QTextEdit(verticalLayoutWidget_3);
        textEdit_TBS_cam0->setObjectName(QString::fromUtf8("textEdit_TBS_cam0"));
        textEdit_TBS_cam0->setMinimumSize(QSize(150, 50));
        textEdit_TBS_cam0->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_25->addWidget(textEdit_TBS_cam0);


        verticalLayout->addLayout(horizontalLayout_25);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(150, 25));
        label_3->setMaximumSize(QSize(10000, 10000));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_3);

        lineEdit_rate_cam0 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_rate_cam0->setObjectName(QString::fromUtf8("lineEdit_rate_cam0"));
        lineEdit_rate_cam0->setMinimumSize(QSize(100, 35));
        lineEdit_rate_cam0->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_5->addWidget(lineEdit_rate_cam0);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(150, 25));
        label_4->setMaximumSize(QSize(10000, 10000));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_4);

        lineEdit_resolution_cam0 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_resolution_cam0->setObjectName(QString::fromUtf8("lineEdit_resolution_cam0"));
        lineEdit_resolution_cam0->setMinimumSize(QSize(100, 35));
        lineEdit_resolution_cam0->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_6->addWidget(lineEdit_resolution_cam0);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(150, 25));
        label_5->setMaximumSize(QSize(10000, 10000));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_5);

        lineEdit_camera_model_cam0 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_camera_model_cam0->setObjectName(QString::fromUtf8("lineEdit_camera_model_cam0"));
        lineEdit_camera_model_cam0->setMinimumSize(QSize(100, 35));
        lineEdit_camera_model_cam0->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_7->addWidget(lineEdit_camera_model_cam0);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_6 = new QLabel(verticalLayoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(150, 25));
        label_6->setMaximumSize(QSize(10000, 10000));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_6);

        lineEdit_fu_cam0 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_fu_cam0->setObjectName(QString::fromUtf8("lineEdit_fu_cam0"));
        lineEdit_fu_cam0->setMinimumSize(QSize(100, 35));
        lineEdit_fu_cam0->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_8->addWidget(lineEdit_fu_cam0);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(150, 25));
        label_7->setMaximumSize(QSize(10000, 10000));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_7);

        lineEdit_fv_cam0 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_fv_cam0->setObjectName(QString::fromUtf8("lineEdit_fv_cam0"));
        lineEdit_fv_cam0->setMinimumSize(QSize(100, 35));
        lineEdit_fv_cam0->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_9->addWidget(lineEdit_fv_cam0);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_13 = new QLabel(verticalLayoutWidget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(150, 25));
        label_13->setMaximumSize(QSize(10000, 10000));
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(label_13);

        lineEdit_cu_cam0 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_cu_cam0->setObjectName(QString::fromUtf8("lineEdit_cu_cam0"));
        lineEdit_cu_cam0->setMinimumSize(QSize(100, 35));
        lineEdit_cu_cam0->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_15->addWidget(lineEdit_cu_cam0);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_11 = new QLabel(verticalLayoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(150, 25));
        label_11->setMaximumSize(QSize(10000, 10000));
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(label_11);

        lineEdit_cv_cam0 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_cv_cam0->setObjectName(QString::fromUtf8("lineEdit_cv_cam0"));
        lineEdit_cv_cam0->setMinimumSize(QSize(100, 35));
        lineEdit_cv_cam0->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_13->addWidget(lineEdit_cv_cam0);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_10 = new QLabel(verticalLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(150, 25));
        label_10->setMaximumSize(QSize(10000, 10000));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_10);

        lineEdit_distortion_model_cam0 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_distortion_model_cam0->setObjectName(QString::fromUtf8("lineEdit_distortion_model_cam0"));
        lineEdit_distortion_model_cam0->setMinimumSize(QSize(100, 35));
        lineEdit_distortion_model_cam0->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_12->addWidget(lineEdit_distortion_model_cam0);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_8 = new QLabel(verticalLayoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(150, 25));
        label_8->setMaximumSize(QSize(10000, 10000));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_8);

        textEdit_coefficients_cam0 = new QTextEdit(verticalLayoutWidget_3);
        textEdit_coefficients_cam0->setObjectName(QString::fromUtf8("textEdit_coefficients_cam0"));
        textEdit_coefficients_cam0->setMinimumSize(QSize(150, 60));
        textEdit_coefficients_cam0->setMaximumSize(QSize(10000, 60));

        horizontalLayout_10->addWidget(textEdit_coefficients_cam0);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, -1, 10, -1);
        btn_LoadFromFile_cam0 = new QPushButton(verticalLayoutWidget_3);
        btn_LoadFromFile_cam0->setObjectName(QString::fromUtf8("btn_LoadFromFile_cam0"));
        btn_LoadFromFile_cam0->setMinimumSize(QSize(150, 30));

        horizontalLayout->addWidget(btn_LoadFromFile_cam0);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_Confirm_cam0 = new QPushButton(verticalLayoutWidget_3);
        btn_Confirm_cam0->setObjectName(QString::fromUtf8("btn_Confirm_cam0"));
        btn_Confirm_cam0->setMinimumSize(QSize(150, 30));

        horizontalLayout->addWidget(btn_Confirm_cam0);


        verticalLayout->addLayout(horizontalLayout);

        tabWidget->addTab(tab_cam0Para, QString());
        tab_cam1Para = new QWidget();
        tab_cam1Para->setObjectName(QString::fromUtf8("tab_cam1Para"));
        verticalLayoutWidget_4 = new QWidget(tab_cam1Para);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 10, 371, 541));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 0, 5, 0);
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_22 = new QLabel(verticalLayoutWidget_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMinimumSize(QSize(150, 25));
        label_22->setMaximumSize(QSize(10000, 10000));
        label_22->setFont(font);
        label_22->setAlignment(Qt::AlignCenter);

        horizontalLayout_24->addWidget(label_22);

        textEdit_TBS_cam1 = new QTextEdit(verticalLayoutWidget_4);
        textEdit_TBS_cam1->setObjectName(QString::fromUtf8("textEdit_TBS_cam1"));
        textEdit_TBS_cam1->setMinimumSize(QSize(150, 50));
        textEdit_TBS_cam1->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_24->addWidget(textEdit_TBS_cam1);


        verticalLayout_2->addLayout(horizontalLayout_24);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_12 = new QLabel(verticalLayoutWidget_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(150, 25));
        label_12->setMaximumSize(QSize(10000, 10000));
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(label_12);

        lineEdit_rate_cam1 = new QLineEdit(verticalLayoutWidget_4);
        lineEdit_rate_cam1->setObjectName(QString::fromUtf8("lineEdit_rate_cam1"));
        lineEdit_rate_cam1->setMinimumSize(QSize(100, 35));
        lineEdit_rate_cam1->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_14->addWidget(lineEdit_rate_cam1);


        verticalLayout_2->addLayout(horizontalLayout_14);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_14 = new QLabel(verticalLayoutWidget_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(150, 25));
        label_14->setMaximumSize(QSize(10000, 10000));
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_16->addWidget(label_14);

        lineEdit_resolution_cam1 = new QLineEdit(verticalLayoutWidget_4);
        lineEdit_resolution_cam1->setObjectName(QString::fromUtf8("lineEdit_resolution_cam1"));
        lineEdit_resolution_cam1->setMinimumSize(QSize(100, 35));
        lineEdit_resolution_cam1->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_16->addWidget(lineEdit_resolution_cam1);


        verticalLayout_2->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_15 = new QLabel(verticalLayoutWidget_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(150, 25));
        label_15->setMaximumSize(QSize(10000, 10000));
        label_15->setFont(font);
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_15);

        lineEdit_camera_model_cam1 = new QLineEdit(verticalLayoutWidget_4);
        lineEdit_camera_model_cam1->setObjectName(QString::fromUtf8("lineEdit_camera_model_cam1"));
        lineEdit_camera_model_cam1->setMinimumSize(QSize(100, 35));
        lineEdit_camera_model_cam1->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_17->addWidget(lineEdit_camera_model_cam1);


        verticalLayout_2->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_16 = new QLabel(verticalLayoutWidget_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(150, 25));
        label_16->setMaximumSize(QSize(10000, 10000));
        label_16->setFont(font);
        label_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_18->addWidget(label_16);

        lineEdit_fu_cam1 = new QLineEdit(verticalLayoutWidget_4);
        lineEdit_fu_cam1->setObjectName(QString::fromUtf8("lineEdit_fu_cam1"));
        lineEdit_fu_cam1->setMinimumSize(QSize(100, 35));
        lineEdit_fu_cam1->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_18->addWidget(lineEdit_fu_cam1);


        verticalLayout_2->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_17 = new QLabel(verticalLayoutWidget_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(150, 25));
        label_17->setMaximumSize(QSize(10000, 10000));
        label_17->setFont(font);
        label_17->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(label_17);

        lineEdit_fv_cam1 = new QLineEdit(verticalLayoutWidget_4);
        lineEdit_fv_cam1->setObjectName(QString::fromUtf8("lineEdit_fv_cam1"));
        lineEdit_fv_cam1->setMinimumSize(QSize(100, 35));
        lineEdit_fv_cam1->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_19->addWidget(lineEdit_fv_cam1);


        verticalLayout_2->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_18 = new QLabel(verticalLayoutWidget_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMinimumSize(QSize(150, 25));
        label_18->setMaximumSize(QSize(10000, 10000));
        label_18->setFont(font);
        label_18->setAlignment(Qt::AlignCenter);

        horizontalLayout_20->addWidget(label_18);

        lineEdit_cu_cam1 = new QLineEdit(verticalLayoutWidget_4);
        lineEdit_cu_cam1->setObjectName(QString::fromUtf8("lineEdit_cu_cam1"));
        lineEdit_cu_cam1->setMinimumSize(QSize(100, 35));
        lineEdit_cu_cam1->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_20->addWidget(lineEdit_cu_cam1);


        verticalLayout_2->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_19 = new QLabel(verticalLayoutWidget_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMinimumSize(QSize(150, 25));
        label_19->setMaximumSize(QSize(10000, 10000));
        label_19->setFont(font);
        label_19->setAlignment(Qt::AlignCenter);

        horizontalLayout_21->addWidget(label_19);

        lineEdit_cv_cam1 = new QLineEdit(verticalLayoutWidget_4);
        lineEdit_cv_cam1->setObjectName(QString::fromUtf8("lineEdit_cv_cam1"));
        lineEdit_cv_cam1->setMinimumSize(QSize(100, 35));
        lineEdit_cv_cam1->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_21->addWidget(lineEdit_cv_cam1);


        verticalLayout_2->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_20 = new QLabel(verticalLayoutWidget_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setMinimumSize(QSize(150, 25));
        label_20->setMaximumSize(QSize(10000, 10000));
        label_20->setFont(font);
        label_20->setAlignment(Qt::AlignCenter);

        horizontalLayout_22->addWidget(label_20);

        lineEdit_distortion_model_cam1 = new QLineEdit(verticalLayoutWidget_4);
        lineEdit_distortion_model_cam1->setObjectName(QString::fromUtf8("lineEdit_distortion_model_cam1"));
        lineEdit_distortion_model_cam1->setMinimumSize(QSize(100, 35));
        lineEdit_distortion_model_cam1->setMaximumSize(QSize(10000, 10000));

        horizontalLayout_22->addWidget(lineEdit_distortion_model_cam1);


        verticalLayout_2->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_21 = new QLabel(verticalLayoutWidget_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMinimumSize(QSize(150, 25));
        label_21->setMaximumSize(QSize(10000, 10000));
        label_21->setFont(font);
        label_21->setAlignment(Qt::AlignCenter);

        horizontalLayout_23->addWidget(label_21);

        textEdit_coefficients_cam1 = new QTextEdit(verticalLayoutWidget_4);
        textEdit_coefficients_cam1->setObjectName(QString::fromUtf8("textEdit_coefficients_cam1"));
        textEdit_coefficients_cam1->setMinimumSize(QSize(150, 60));
        textEdit_coefficients_cam1->setMaximumSize(QSize(10000, 60));

        horizontalLayout_23->addWidget(textEdit_coefficients_cam1);


        verticalLayout_2->addLayout(horizontalLayout_23);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, -1, 10, -1);
        btn_LoadFromFile_cam1 = new QPushButton(verticalLayoutWidget_4);
        btn_LoadFromFile_cam1->setObjectName(QString::fromUtf8("btn_LoadFromFile_cam1"));
        btn_LoadFromFile_cam1->setMinimumSize(QSize(150, 30));

        horizontalLayout_2->addWidget(btn_LoadFromFile_cam1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_Confirm_cam1 = new QPushButton(verticalLayoutWidget_4);
        btn_Confirm_cam1->setObjectName(QString::fromUtf8("btn_Confirm_cam1"));
        btn_Confirm_cam1->setMinimumSize(QSize(150, 30));

        horizontalLayout_2->addWidget(btn_Confirm_cam1);


        verticalLayout_2->addLayout(horizontalLayout_2);

        tabWidget->addTab(tab_cam1Para, QString());
        configurationClass->setCentralWidget(centralWidget);

        retranslateUi(configurationClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(configurationClass);
    } // setupUi

    void retranslateUi(QMainWindow *configurationClass)
    {
        configurationClass->setWindowTitle(QCoreApplication::translate("configurationClass", "configuration", nullptr));
        label_23->setText(QCoreApplication::translate("configurationClass", "TBS", nullptr));
        textEdit_TBS_cam0->setHtml(QCoreApplication::translate("configurationClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("configurationClass", "rate_hz", nullptr));
        label_4->setText(QCoreApplication::translate("configurationClass", "resolution", nullptr));
        label_5->setText(QCoreApplication::translate("configurationClass", "camera_model", nullptr));
        label_6->setText(QCoreApplication::translate("configurationClass", "fu", nullptr));
        label_7->setText(QCoreApplication::translate("configurationClass", "fv", nullptr));
        label_13->setText(QCoreApplication::translate("configurationClass", "cu", nullptr));
        label_11->setText(QCoreApplication::translate("configurationClass", "cv", nullptr));
        label_10->setText(QCoreApplication::translate("configurationClass", "distortion_model", nullptr));
        label_8->setText(QCoreApplication::translate("configurationClass", "coefficients", nullptr));
        textEdit_coefficients_cam0->setHtml(QCoreApplication::translate("configurationClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        btn_LoadFromFile_cam0->setText(QCoreApplication::translate("configurationClass", "\346\226\207\344\273\266\350\275\275\345\205\245cam0\351\205\215\347\275\256", nullptr));
        btn_Confirm_cam0->setText(QCoreApplication::translate("configurationClass", "\347\241\256\345\256\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_cam0Para), QCoreApplication::translate("configurationClass", "\347\233\270\346\234\2720\345\217\202\346\225\260", nullptr));
        label_22->setText(QCoreApplication::translate("configurationClass", "TBS", nullptr));
        textEdit_TBS_cam1->setHtml(QCoreApplication::translate("configurationClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("configurationClass", "rate_hz", nullptr));
        label_14->setText(QCoreApplication::translate("configurationClass", "resolution", nullptr));
        label_15->setText(QCoreApplication::translate("configurationClass", "camera_model", nullptr));
        label_16->setText(QCoreApplication::translate("configurationClass", "fu", nullptr));
        label_17->setText(QCoreApplication::translate("configurationClass", "fv", nullptr));
        label_18->setText(QCoreApplication::translate("configurationClass", "cu", nullptr));
        label_19->setText(QCoreApplication::translate("configurationClass", "cv", nullptr));
        label_20->setText(QCoreApplication::translate("configurationClass", "distortion_model", nullptr));
        label_21->setText(QCoreApplication::translate("configurationClass", "coefficients", nullptr));
        textEdit_coefficients_cam1->setHtml(QCoreApplication::translate("configurationClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        btn_LoadFromFile_cam1->setText(QCoreApplication::translate("configurationClass", "\346\226\207\344\273\266\350\275\275\345\205\245cam1\351\205\215\347\275\256", nullptr));
        btn_Confirm_cam1->setText(QCoreApplication::translate("configurationClass", "\347\241\256\345\256\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_cam1Para), QCoreApplication::translate("configurationClass", "\347\233\270\346\234\2721\345\217\202\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class configurationClass: public Ui_configurationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATION_H
