#include <iostream>
#include <cmath>
using namespace std;
class CCircle
{
private:
    enum
    {
        seperation, //相离
        intersection,
        tangent_internal, //内切
        tangent_external
    };

public:
    CCircle(double, double, double);
    ~CCircle();
    double X, Y, R;
    double CountDistance(CCircle &);
    int Judge(CCircle &);
    //成员函数*1和非成员函数*1，计算两点
    //定义一个成员函数，Relationship
    //定义一个成员函数，判断相交，相离，还是相切
};
double CCircle::CountDistance(CCircle &other)
{
    double x = this->X - other.X;
    double y = this->Y - other.Y;
    return sqrt(x * x + y * y);
}
int CCircle::Judge(CCircle &other)
{
    double dis = this->CountDistance(other);
    if (dis > this->R + other.R)
    {
        return seperation;
    }
    else if (dis == this->R + other.R)
    {
        return tangent_external;
    }
    else if (dis == abs(this->R - other.R))
    {
        return tangent_internal;
    }
    else
    {
        return intersection;
    }
}
CCircle::CCircle(double X, double Y, double Radius)
{
    this->X = X;
    this->Y = Y;
    this->R = Radius;
}

CCircle::~CCircle()
{
}
double CountDistance(CCircle &a, CCircle &b)
{
    double x = a.X - b.X;
    double y = a.Y - b.Y;
    return sqrt(x * x + y * y);
}
int main()
{
}