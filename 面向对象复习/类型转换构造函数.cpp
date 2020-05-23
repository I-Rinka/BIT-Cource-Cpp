#include <iostream>
using namespace std;
class MyClass
{
private:
public:
    int d;
    MyClass(/* args */);
    MyClass(int i) //类型转换构造函数
    {
        this->d = 20;
    }
    ~MyClass();
};

MyClass::MyClass(/* args */)
{
}

MyClass::~MyClass()
{
}
class Class2
{
private:
public:
    int d;
    Class2(/* args */);
    Class2(MyClass &t)
    {
        this->d = t.d;
    }
    ~Class2();
};

Class2::Class2()
{
}
Class2::~Class2()
{

}
int main(int argc, char const *argv[])
{
    /* code */
    MyClass t = 20; //其实可以把复制构造函数看为类型转换构造函数的一种
    cout << t.d << endl;
    Class2 t2 = t;//初始化构造函数还可以适用于除基本类型外的其他类型
    cout << t2.d << endl;
    return 0;
}
