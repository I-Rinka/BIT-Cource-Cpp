#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    stringstream t("12 34 56 789 1011");
    //在初始化后的sstream后继续使用流输入会使得
    t << 98;
    t << " ";
    t << 7654;
    // t << "i want you" << endl;
    // t << "b";
    char tt[20];
    int in;
    while (!t.eof())
    {
        // t >> tt;
        t >> in;
        cout << in << endl; //自动进行字符串到整形的转换，无敌！
    }
}