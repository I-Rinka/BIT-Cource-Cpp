#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
    char str[256];
    scanf("%s", str);
    int l = strlen(str);
    bool judge = true;
    for (int i = 0; i < l / 2; i++)
    {
        if (str[i] != str[l - i - 1])
        {
            judge = false;
        }
    }
    if (judge)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}
