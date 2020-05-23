#include <iostream>
using namespace std;
class Complex
{
private:
    double real; //表示复数的实部和虚部
    double image;
    void assign(double real, double image) //同时给实部和虚部赋值代码复用度很高，因此在private定义一个函数
    {
        this->real = real;
        this->image = image;
    }

public:
    Complex() //默认构造函数实部虚部都赋值为0
    {
        assign(0, 0);
    }
    Complex(double real, double image)
    {
        assign(real, image);
    }
    Complex(Complex &other) //其实在本题中，系统自带的构造函数足够使用，不需要自己构造
    {
        assign(other.real, other.image);
    }
    ~Complex();
    Complex &operator=(Complex const &other) //赋值重载时返回值为引用，并且传入参数前要加const
    {
        assign(other.real, other.image);
        return (*this); //为了有连续赋值功能，返回*this
    }
    Complex operator+(Complex &other) //相加后返回新值
    {
        Complex out;
        out.image = this->image + other.image;
        out.real = this->real + other.real;
        return out; //返回的是新加出来的值
    }
    Complex &operator+=(Complex const &other) //自增重载
    {
        this->image += other.image;
        this->real += other.real;
        return *this;
    }
    friend ostream &operator<<(ostream &o, Complex &c); //流输入输出设置为友元方便访问private的实部和虚部
};

ostream &operator<<(ostream &o, Complex &c)
{
    if (c.real == 0 && c.image == 0) //判断实部虚部是否为0
    {
        o << 0;
    }
    else
    {
        if (c.real == 0)
        {
            o << c.image << 'i';
        }
        else
        {
            o << c.real;
            if (c.image != 0)
            {
                o << '+' << c.image << 'i';
            }
        }
    }
    return o;
}
Complex::~Complex()
{
}

int main()
{
    Complex C1(1, 2), C2;
    Complex C3 = C2;
    cout << " C3 = " << C3 << endl;
    C2 = C1 + C3;
    cout << " C2 = " << C2 << endl;
    C2 += C1;
    cout << " C2 = " << C2 << endl;
}
