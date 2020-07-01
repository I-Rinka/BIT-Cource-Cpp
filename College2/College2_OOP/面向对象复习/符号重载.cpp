#include <iostream>
using namespace std;

class MyClass
{
private:
    /* data */
public:
    MyClass(/* args */);
    int d;
    static int i;
    void operator+();
    MyClass &operator+(int i)
    {
        this->d += i;
        return *this;
    }
    MyClass &operator++(int i)
    {
        this->d += i * 2;
        return *this;
    }
    MyClass &operator=(MyClass &b)
    {
        this->i++;
        this->d = b.d;
        return *this;
    }
    ~MyClass();
};
int MyClass::i = 0;
void MyClass::operator+()
{
    cout << "plus!" << endl;
}
MyClass::MyClass(/* args */)
{
    this->i++;
    cout << "MyClass" << this->i << "created" << endl;
    this->d = 0;
}

MyClass::~MyClass()
{
    cout << "MyClass" << this->i << "decreated" << endl;
    // this->i--;
}

ostream &operator<<(ostream &o, const MyClass &a) //重载了ostream中的对象，之所以有用友元的写法，是为了方便访问类内的成员。之所以要写外面，是因为这个重载的ostream是属于ostream的，得写外面
{
    o << "MyClass" << a.d << endl;
    return o;
}
//之所以输入输出流的重载函数要写两个参数而不是一个，是因为类外面声明的符号重载都写两个（没有了默认的“this”）
/*
ostream &operator<<(const MyClass &a)
{

}
*/
MyClass &operator&=(MyClass &a, MyClass &b)
{
    MyClass c;
    c.d = a.d - b.d;
    //return c;//函数内的引用不能直接返回一个临时变量，函数消亡时直接gg
    return a; //c直接跑路了？？
}
ostream &operator>>(ostream &o, MyClass const &a)
{
    o << "hahah" << a << endl;
    return o;
}
int main(int argc, char const *argv[])
{
    MyClass test;
    test.operator+();
    +test; //空的符号重载可以直接前置符号使用
    test = test + 2;
    cout << test.d << endl;
    test = test++;     //自增符号一定要跟一个没有用的参数，并且甚至不允许从后面赋值
    (test + 1).d = -1; //引用的奇妙用法
    cout << test.d << endl;
    cout << test;
    MyClass test2;
    test2.d = -100;
    MyClass test3;
    test3 = (test &= test2); //一个非常mind fucker的写法
    cout >> test3;
    return 0;
    //1、加号一般是直接返回原类
    //2、赋值返回引用类
    //3、输入输出也是引用
}
