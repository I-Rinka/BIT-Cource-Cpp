#include <iostream>
using namespace std;
class CopyClass
{
private:
    /* data */

public:
    static int copyTurns;
    int d;
    char name[20];
    CopyClass(/* args */);
    CopyClass(int d)
    {
        this->d = d;
    } //类型转换构造函数
    CopyClass(CopyClass &c)
    {
        CopyClass::copyTurns++;
        printf("copy%d!\n", CopyClass::copyTurns);
        for (int i = 0; i < 20; i++)
        {
            this->name[i] = c.name[i];
        }
    }
    ~CopyClass();
};
int CopyClass::copyTurns = 0; //静态初始变量一定要加个前缀
CopyClass::CopyClass(/* args */)
{
    char *t = "I fuck you every day";
    for (int i = 0; i < 20; i++)
    {
        this->name[i] = t[i];
    }
}
CopyClass::~CopyClass()
{
}
int Type2(CopyClass t)
{
    int z = t.d;
    cout << "临时变量的值：" << t.name[0] << endl;
    return z;
}
CopyClass Type3(int i)
{
    CopyClass a;
    a.d = i;
    cout << &a.d << endl;
    cout << &a << endl;
    return a;
}
int main(int argc, char const *argv[])
{
    CopyClass t;
    t.d = 10;
    t.name[0] = 'F';
    CopyClass p = t; //1、使用了自己构造的后，系统的复制构造函数被覆盖，停止了值的传递，
    cout << p.d << endl;
    cout << Type2(p) << endl; //2、传入函数的临时变量时，也调用了自定义的复制函数
    cout << "p的地址：" << endl;
    cout << &p.d << endl;
    cout << &p << endl;
    cout << p.name[0] << endl;
    // cout << Type3(3).d << endl; //第三种返回值的情况没有使用自定义的copy
    p = Type3(4);
    cout << "p后来的地址：" << endl;
    cout << &p.d << endl;
    cout << &p << endl;
    cout << p.name[0] << endl;
    return 0;
}
