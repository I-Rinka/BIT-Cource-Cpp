#include <iostream>
#include <cstring>
using namespace std;
class MyClass
{
private:
    /* data */
public:
    char ClassName[20];
    MyClass(/* args */);
    MyClass(MyClass const &a)
    {
        strcpy(this->ClassName, a.ClassName);
        cout << "复制构造函数发动" << endl;
    }
    MyClass &operator=(MyClass const &a)
    {
        strcpy(this->ClassName, a.ClassName);
        cout << "operator '=' 发动" << endl;
        return *this;
    }
    ~MyClass();
};

MyClass::MyClass(/* args */)
{
}
MyClass::~MyClass()
{
}
/*
MyClass& operator=(MyClass &a,MyClass cons &b)
{
赋值只能是成员函数
}*/
int main(int argc, char const *argv[])
{
    MyClass *mc = new MyClass;
    strcpy(mc->ClassName, "fuck");
    cout << mc->ClassName << endl; //cout可以直接输出字符串
    MyClass b = *mc;
    cout << b.ClassName << endl; //cout可以直接输出字符串
    MyClass c;
    c = *mc;
    cout << c.ClassName << endl; //cout可以直接输出字符串
    return 0;
}
