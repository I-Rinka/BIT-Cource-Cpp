#include <iostream>
using namespace std;
void printEdge(int n, char c)
{
    while (n--)
    {
        printf("%c", c);
    }
    printf("\n");
}
void printMiddle(int n, char c)
{
    printf("%c", c);
    n -= 2;
    while (n--)
    {
        printf(" ");
    }
    printf("%c\n", c);
}
int main(int argc, char const *argv[])
{
    int n;
    char c;
    scanf("%d %c", &n, &c);
    for (int i = 0; i < (n + 1) / 2; i++)
    {
        if (i == 0 || i+1 == (n + 1) / 2)
        {
            printEdge(n, c);
        }
        else
        {
            printMiddle(n, c);
        }
    }
    return 0;
}
