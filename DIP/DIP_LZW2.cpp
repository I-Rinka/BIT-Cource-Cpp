#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
string Dic[200000];
int main(int argc, char const *argv[])
{
    // freopen("/root/Dev/Cpp/input.txt","r",stdin);
    for (int i = 0; i <= 255; i++)
    {
        Dic[i] = std::to_string(i);
    }
    int row, col;
    cin >> row >> col;
    int dic_size = 256;
    string C;
    string P;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> C;
            string PC;
            if (i == 0 && j == 0)
            {
                PC = C;
            }
            else
            {
                PC = P + "+" + C; //PC=0+87
            }

            int position = -1;
            for (int i = 0; i < dic_size; i++)
            {
                if (PC == Dic[i])
                {
                    P = PC;
                    position = i;
                    break;
                }
            }

            if (position != -1)
            {
                P = PC;
            }
            else
            {
            //0+87找不到//所以输出了个0
                //没找到
                for (int i = 0; i < dic_size; i++)
                {
                    if (P == Dic[i])
                    {
                        cout << i << ' ';
                        break;
                    }
                }
                Dic[dic_size] = PC;
                dic_size++;
                P = C;
            }

            //没有要输出的码字流了
            if (i == row - 1 && j == col - 1)
            {
                for (int i = 0; i < dic_size; i++)
                {
                    if (P == Dic[i])
                    {
                        cout << i << endl;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
