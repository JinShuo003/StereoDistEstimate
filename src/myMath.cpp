#include "myMath.h"
#include <assert.h>

using namespace std;

//����н�
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
//����ģ
double module(const vector<float>& v)
{
    double ret = 0.0;
    for (vector<float>::size_type i = 0; i != v.size(); ++i)
    {
        ret += v[i] * v[i];
    }
    return sqrt(ret);
}

//��������ֵ
double cosine(const vector<float>& v1, const vector<float>& v2)
{
    assert(v1.size() == v2.size());
    return dotProduct(v1, v2) / (module(v1) * module(v2));
}

//�Ƿ�Ϊ��λ��
bool IsIdentityMatrix(cv::Mat mat) {
    //����
    if (mat.size().width != mat.size().height) {
        return false;
    }
    for (int i = 0; i < mat.size().height; i++)
    {
        for (int j = 0; j < mat.size().width; j++)
        {
            //�Խ���Ԫ�ر���Ϊ1
            if (i == j) {
                if (fabs(mat.at<double>(i, j) - 1) >= 1e-2) {
                    return false;
                }
            }
            //����Ԫ�ر���Ϊ0
            else {
                if (fabs(mat.at<double>(i, j)) >= 1e-2) {
                    return false;
                }
            }
        }
    }
    return true;
}