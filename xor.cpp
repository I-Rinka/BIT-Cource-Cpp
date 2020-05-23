#include <iostream>
using namespace std;
int main()
{
    int a = 123;
    int b = 456;
    printf("%d\n", a ^ b);
    int c = 234;
    a = a ^ c;
    b = b ^ c;
    printf("%d", a ^ b);
}