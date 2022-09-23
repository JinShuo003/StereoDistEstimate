#include "myMath.h"
#include <assert.h>

using namespace std;

//计算夹角
double dotProduct(const vector<float>& v1, const vector<float>& v2)
{
    assert(v1.size() == v2.size());
    double ret = 0.0;
    for (vector<float>::size_type i = 0; i != v1.size(); ++i)
    {
        ret += v1[i] * v2[i];
    }
    return ret;
}
//向量模
double module(const vector<float>& v)
{
    double ret = 0.0;
    for (vector<float>::size_type i = 0; i != v.size(); ++i)
    {
        ret += v[i] * v[i];
    }
    return sqrt(ret);
}

//计算余弦值
double cosine(const vector<float>& v1, const vector<float>& v2)
{
    assert(v1.size() == v2.size());
    return dotProduct(v1, v2) / (module(v1) * module(v2));
}

//是否为单位阵
bool IsIdentityMatrix(cv::Mat mat) {
    //方阵
    if (mat.size().width != mat.size().height) {
        return false;
    }
    for (int i = 0; i < mat.size().height; i++)
    {
        for (int j = 0; j < mat.size().width; j++)
        {
            //对角线元素必须为1
            if (i == j) {
                if (fabs(mat.at<double>(i, j) - 1) >= 1e-2) {
                    return false;
                }
            }
            //其余元素必须为0
            else {
                if (fabs(mat.at<double>(i, j)) >= 1e-2) {
                    return false;
                }
            }
        }
    }
    return true;
}