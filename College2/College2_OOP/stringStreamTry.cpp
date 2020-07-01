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
    t << "2.333";
    double dou;//居然对浮点数不管用？？
    t >> dou;
    t << 2.44;
    cout << dou << endl;
    string ff;
    t >> ff;
    cout << ff << endl;
    ff = to_string(1234);
    cout << ff << endl;
}