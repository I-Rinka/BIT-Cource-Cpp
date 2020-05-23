#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    /*御用行输入*/
    stringstream ss;
    while (getline(cin, str))
    {
        cout << str << endl;
        ss << str;
        char n;
        // ss >> n;
        while (ss)
        {
            ss >> n;
            cout << n;
        }
        //难道C++只能这样分词？
        cout << endl;
    }
    return 0;
}