#include <iostream>
using namespace std;
class MyClass
{
public:
    static int j;
};
int MyClass::j = 1;//静态成员变量使用前一定要在成员变量外初始化
int main(int argc, char const *argv[])
{
    MyClass *t = new MyClass();
    MyClass a;
    t->j=520;
    printf("%d", a.j);
}
