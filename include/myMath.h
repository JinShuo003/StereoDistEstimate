#pragma once
#include <vector>
#include "opencv.hpp"

using namespace std;

double dotProduct(const vector<float>& v1, const vector<float>& v2);
double module(const vector<float>& v);
double cosine(const vector<float>& v1, const vector<float>& v2);
bool IsIdentityMatrix(cv::Mat mat);
