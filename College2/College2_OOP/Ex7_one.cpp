#include <iostream>
using namespace std;
int compare(const void *a, const void *b)
{
    return *(int *)a < *(int *)b ? -1 : 1;
}
void Sort(int *a, int length)
{
    qsort(a, length, sizeof(int), compare);
}
void Show(int *a, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void Show(int length, int *a)
{
    for (int i = length - 1; i >= 0; i--)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main()
{
    int number;
    scanf("%d ", &number);
    int a[number];
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &a[i]);
    }
    Sort(a, number);
    Show(a, number);
    Show(number, a);
}