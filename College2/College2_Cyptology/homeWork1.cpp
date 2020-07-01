#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void preProcess(vector<vector<char>> &t)
{
    for (int i = 0; i < t.size(); i++)
    {
        for (int j = 0; j < t[i].size(); j++)
        {
            t[i][j] -= 'A';
        }
    }
}
void decode(vector<vector<char>> &t, int k) //输入k和对应的密码容器，得到对应的解密结果
{
    for (int i = 0; i < t.size(); i++)
    {
        for (int j = 0; j < t[i].size(); j++)
        {
            t[i][j] = (t[i][j] + k) % 26;
        }
    }
}
void output(vector<vector<char>> &t)
{
    for (int i = 0; i < t.size(); i++)
    {
        for (int j = 0; j < t[i].size(); j++)
        {
            cout << (char)(t[i][j] + 'A');
        }
        cout << ' ';
    }
    cout << endl;
}
int main()
{
    vector<vector<char>> store;
    while (true) //输入密文
    {
        vector<char> t;
        char c;
        while (cin.get(c))
        {
            if (c == ' ' || c == '\n')
            {
                break;
            }
            t.push_back(c);
        }
        store.push_back(t);
        if (c == '\n')
        {
            break;
        }
    }
    int k = 0;
    preProcess(store); //初始化
    for (; k < 26; k++)
    {
        decode(store, k);
        output(store);
        cout << "Is it the right answer ?" << '\n' //如果得到了正确的答案，需要手动停止程序
             << "y/n" << endl;
        char judge;
        cin.get(judge);
        getchar();
        if (judge == 'y' || judge == 'Y')
        {
            cout << "key is " << 26 - k << endl;
            break; //如果是明文的话，程序停止，并输出对应的密钥
        }
        decode(store, -k);
    }
}