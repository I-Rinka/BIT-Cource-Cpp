#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    n = 10;
    int const *p = &n;
    // *p=20; 直接通过指针改值会报错
    //可以把const的指针视作read only
    const int *a = &n; //const int 和 int const都是正确写法
    int *m = &n;
    cout << *p << endl;
    *m = 20;//如果不通过read only的指针仍然是可以继续改值的
    cout << *p << endl;
    return 0;
}