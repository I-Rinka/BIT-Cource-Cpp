#include <iostream>
using namespace std;
class B1
{
    int b;

public:
    B1(int i) : b(i) { cout << "Constructor B1:" << b << endl; }
    ~B1() { cout << "Des B1:" << b << endl; }
};
class B2
{
    int b;

public:
    B2(int i) : b(i) { cout << "Constructor B2:" << b << endl; }
    ~B2() { cout << "Des B2:" << b << endl; }
};
class Y : public B1, public B2
{
    B1 x1, x2;
    B1 &x3;

public:
    const B2 x4;
    static B1 x5;
    Y(int i, int j, int m, int n) : x2(i), x1(j), B2(m), B1(n), x3(x2), x4(m)
    {
        cout << "Constructor Y:" << endl;
    }
    ~Y() { cout << "Des Y:" << endl; }
};
int main()
{
    Y as(1, 2, 3, 4);
}