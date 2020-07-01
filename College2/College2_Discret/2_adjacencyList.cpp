#include <iostream>
#include <string>
#include <vector>
using namespace std;
int charTable[256];
vector<string> Data;
void input()
{
    string str;
    while (getline(cin, str))
    {
        string *t = new string(str);
        for (int i = 0; i < (*t).size(); i++)
        {
            if ((*t)[i] != ' ')
            {
                charTable[(*t)[i]] = 1;
            }
        }
        Data.push_back(*t);
    }
}
int findP(char c)
{
    return charTable[(int)c];
}
void output()
{
    int len = 0;
    for (int i = 0; i < 256; i++)
    {
        if (charTable[i])
        {
            charTable[i] = len;
            len++;
        }
    }
    int OutTable[len][len];
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            OutTable[i][j] = 0;
        }
    }
    for (int i = 0; i < Data.size(); i++)
    {
        for (int j = 2; j < Data[i].size(); j++)
        {
            if (Data[i][j] != ' ')
            {
                OutTable[findP(Data[i][0])][findP(Data[i][j])]++;
            }
        }
    }
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            cout << OutTable[i][j];
            if (j != len - 1)
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
}
int main(int argc, char const *argv[])
{
    input();
    output();

    return 0;
}
