#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    stringstream t("a");
    printf("fuck??");
    t << "ssdfsdf sdfsdf" << endl;
    char tt[20];
    t >> tt;
    cout << tt;
}