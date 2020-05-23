#include <iostream>
using namespace std;
class Shape
{
public:
    virtual double Area() = 0; //纯虚函数
};
class Circle : public Shape
{
private:
    double Radius;//半径成员

public:
    Circle(double r)
    {
        this->Radius = r;
    }
    virtual double Area() //父类虚函数的实现
    {
        return 3.14 * this->Radius * this->Radius;
    }
};
class Triangle : public Shape
{
private:
    double Bottom;//底部边长和高
    double Height;

public:
    Triangle(double B, double H)
    {
        this->Bottom = B;
        this->Height = H;
    }
    virtual double Area() //父类虚函数的实现
    {
        return this->Bottom * this->Height / 2;
    }
};
double PrintArea(Shape &s)
{
    return s.Area(); //得到面积
}
int main()
{
    Shape *p = new Circle(2);
    cout << "The area of the circle is: " << PrintArea(*p) << endl;
    Triangle triangle(3, 4);
    cout << "The area of the triangle is: " << PrintArea(triangle) << endl;
    delete p;
}
