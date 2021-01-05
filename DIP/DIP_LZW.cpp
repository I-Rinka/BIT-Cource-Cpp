#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
class LZW
{
public:
    LZW();
    ~LZW();
    struct Dic
    {
        char *key;
        int position;
        Dic *NEXT;
    };
    Dic *index[200000] = {NULL}; //加快访问速度的索引
    //找P+C的值是否在当前字典中，如果在，则返回字典序，如果不在，则返回-1，并建立一个链表
    int FindKey(const char *PC)
    {
        const char *find_p = strchr(PC, '+');
        if (find_p == NULL)
        {
            int position = atoi(PC);
            return position;
        }
        Dic *cursor = DIC_HEAD->NEXT;
        Dic *pre_cursor = DIC_HEAD;
        bool find_flag = false;
        while (cursor != NULL)
        {
            if (strcmp(PC, cursor->key) == 0)
            {
                find_flag = true;
                break;
            }
            pre_cursor = cursor;
            cursor = cursor->NEXT;
        }
        if (find_flag)
        {
            return cursor->position;
        }
        else
        {
            pre_cursor->NEXT = (Dic *)malloc(sizeof(Dic));
            char *key = (char *)calloc(strlen(PC), sizeof(char));
            if (pre_cursor->NEXT != NULL && key != NULL)
            {
                strcpy(key, PC);
                pre_cursor->NEXT->position = pre_cursor->position + 1;
                index[pre_cursor->NEXT->position - 255] = pre_cursor->NEXT;
                pre_cursor->NEXT->NEXT = NULL;
                pre_cursor->NEXT->key = key;
            }
            return -1;
        }
    }
    char *ItoA(int int_num)
    {
        int temp = int_num;
        int len = 0;
        while (true)
        {
            temp /= 10;
            len++;
            if (!temp)
            {
                break;
            }
        }
        char *ans = (char *)calloc(len + 1, sizeof(char));
        len--;
        if (ans == NULL)
        {
            exit(EXIT_FAILURE);
        }
        temp = int_num;
        int ten = 10;
        while (len >= 0)
        {
            ans[len] = (char)((temp % ten) / (ten / 10)) + '0';
            ten *= 10;
            len--;
        }
        return ans;
    }

private:
    Dic *DIC_HEAD;
};

LZW::LZW()
{
    Dic *my_dic = (Dic *)malloc(sizeof(Dic));
    if (my_dic != NULL)
    {
        DIC_HEAD = my_dic;
        my_dic->key = (char *)malloc(strlen("255") + 1);
        my_dic->position = 255;
        my_dic->NEXT = NULL;
        if (my_dic->key != NULL)
        {
            strcpy(my_dic->key, "255");
        }
        index[0] = my_dic;
    }
    else
    {
        exit(EXIT_FAILURE);
    }
}

LZW::~LZW()
{
    //懒得写析构了
}
int run2()
{
    int row, col;
    LZW Encoder;
    cin >> row >> col;
    int P = 0;
    int C = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> C;
            //P+C的构造
            char *PC_str;
            //得到P+C
            if (P == 0)
            {
                PC_str = Encoder.ItoA(C);
            }
            else
            {
                char *P_str;
                char *C_str;
                bool free_p = false;
                if (P <= 255)
                {
                    P_str = Encoder.ItoA(P);
                    free_p = true;
                }
                else
                {

                    P_str = Encoder.index[P - 255]->key;
                }
                C_str = Encoder.ItoA(C);
                if ((PC_str = (char *)calloc(strlen(P_str) + strlen(C_str) + 2, sizeof(char))) == NULL)
                {
                    exit(EXIT_FAILURE);
                }
                strcpy(PC_str, P_str);
                strcat(PC_str, "+");
                strcat(PC_str, C_str);
                if (free_p)
                {
                    free(P_str);
                }
                free(C_str);
            }
            int rt_val = Encoder.FindKey(PC_str);
            if (rt_val != -1) //找到了
            {
                P = rt_val;
            }
            else
            {
                cout << P << ' ';
                P = C;
            }
            if (i == row - 1 && j == col - 1)
            {
                cout << P << endl;
            }
        }
    }
}
int run()
{
    int row, col;
    LZW lzw;
    cin >> row >> col;
    int P = -1;
    /*
    if (row * col <= 3)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int C;
                cin >> C;
                if (i != row - 1 || j != col - 1)
                {
                    cout << C << ' ';
                }
            }
        }
        cout << endl;
        return 0;
    }*/
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            //对0的输入的处理
            int C;
            cin >> C;
            char *PC_str;
            //得到P+C

            //bug report:fixed,如果P是第一个，应该使用P==-1来界定，而不是P==0，如果是P==0，则如果P是上一个正常输入的0，不可以正确处理
            if (P == -1) //ifP==0不行！得给P重新定值
            {
                PC_str = lzw.ItoA(C); //itoa不能处理0吗？
            }
            else
            {
                char *P_str;
                char *C_str;
                bool free_p = false;
                if (P <= 255)
                {
                    P_str = lzw.ItoA(P);
                    free_p = true;
                }
                else
                {

                    P_str = lzw.index[P - 255]->key;
                }
                C_str = lzw.ItoA(C);
                if ((PC_str = (char *)calloc(strlen(P_str) + strlen(C_str) + 2, sizeof(char))) == NULL)
                {
                    exit(EXIT_FAILURE);
                }
                //P_Str有问题！
                strcpy(PC_str, P_str);
                strcat(PC_str, "+");
                strcat(PC_str, C_str);
                if (free_p)
                {
                    free(P_str);
                }
                free(C_str);
            }
            int position = lzw.FindKey(PC_str);
            if (position == -1)
            {
                //没找到
                cout << P << ' ';
                P = C;
            }
            else
            {
                P = position;
            }
            free(PC_str);

            //最后多处理一次，C为空，只有P
            if (i == row - 1 && j == col - 1)
            {
                cout << P << endl;
            }
        }
    }
    return 0;
}
int main()
{
    //freopen("C:\\Users\\I_Rin\\source\\repos\\DIP2020\\DIP2020\\input.txt", "r", stdin);
    //LZW lzw;
    //cout<< lzw.ItoA(1234567000);
    //run2在0的处理上有问题
    // run2();
    /*错误用例：
2 4
0 87 6 32 
23 128 57 118

>正确输出：
0 87 6 32 23 128 57 118
*/
    run();
}