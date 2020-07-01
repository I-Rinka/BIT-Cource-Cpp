#include <iostream>
using namespace std;
class Why
{
private:
public:
    int a;
    Why(/* args */);
    int gesuse()
    {
        return this->a;
    }
    ~Why();
};

Why::Why(/* args */)
{
    this->a = 20;
}

Why::~Why()
{
}

int printA(Why &F) //不能写成int printA(const Why &F),const变量的成员不能调用非const 的成员函数
{
    cout << F.gesuse() << endl;
}
int main(int argc, char const *argv[])
{
    Why shit;
    printA(shit);
    return 0;
}
