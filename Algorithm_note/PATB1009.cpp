#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char str[81];
    // scanf("%s", str);
    fgets(str, 81, stdin);
    int l = strlen(str);
    l--;
    int pre = l;
    for (int i = l - 1; i >= 0; i--)
    {
        if (str[i] == ' ' || i == 0)
        {
            int j = i;
            if (i != 0)
            {
                j = i + 1;
            }
            while (j < pre)
            {
                printf("%c", str[j]);
                j++;
            }
            printf(" ");
            pre = i;
        }
    }
    printf("\n");
    return 0;
}
