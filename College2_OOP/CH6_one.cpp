#include <iostream>
using namespace std;
class Counted
{
private:
public:
    int id;
    static int count;
    Counted();
    ~Counted();
};
int Counted::count = 0;
Counted::Counted() : id(count++)
{
    cout << "Constructor count:" << id << endl;
}

Counted::~Counted()
{
    cout << "Destructor count:" << id << endl;
}
int main()
{
    // Counted *p1 = new Counted();
    // Counted *p2 = new Counted();
    // delete p1;
    // delete p2;
    Counted *p = new Counted[5]();
    // delete[] p;
    delete p; //程序运行后报错了，对比delete[]，这个相当于只删除了p[0]，也就是p数组中的第一个元素
}