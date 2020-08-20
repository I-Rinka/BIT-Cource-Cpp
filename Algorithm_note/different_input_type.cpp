#include <stdio.h>
void input_str()
{
    char str[10];
    while (scanf("%s", str) != EOF)
    {
        printf(("%s\n"), str);
    }
}
void input_number()
{
    int a;
    while (scanf("%d", &a) != EOF)
    {
        printf("%d\n", a);
    }
}
int main(int argc, char const *argv[])
{
    input_str();
    input_number();
    return 0;
}
