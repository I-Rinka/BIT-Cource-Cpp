#include <iostream>
using namespace std;
class fuckClass
{
public:
    char a;
    fuckClass(char c)
    {
        a = c;
    }
    fuckClass &operator=(fuckClass &t)
    {
        a = t.a;
        return *this;
    }
};
ostream &operator>>(ostream &o, fuckClass &t)
{
    cout << t.a << endl;
}
int main(int argc, char const *argv[])
{
    char a = 'a', b = 'b', c = 'c';
    cout << (a = b = c) << endl;
    fuckClass a1('a'), b1('b'), c1('c');
    cout >> (a1 = b1 = c1) << endl; //只有返回值带引用的函数才能使用调用后还能被赋值，所以为了实现三等号连用，只能&operator=
    return 0;
}
