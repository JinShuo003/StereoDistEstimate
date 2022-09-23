#pragma once

#include "configuration.h"

#include "Eigen/Dense"

#include <iostream>


using std::cout;
using std::endl;

class myDebug: public QObject
{
	Q_OBJECT
public:
	static void CamParaDebug(singleCamPara* pSingleCamPara);
	static void CvMatDebug(cv::Mat CvMat, qint8 mode, QString outputFilePath = QString());

	//Eigen Test
	static void EigenTest();

public:
	enum m_outputMode { console = 0, file = 1 };
	Q_ENUM(m_outputMode)
};

