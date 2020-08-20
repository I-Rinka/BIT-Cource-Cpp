#include <stdio.h>
int main()
{
    int array_size;
    int int_array[200];
    scanf("%d", &array_size);
    for (int i = 0; i < array_size; i++)
    {
        scanf("%d", &int_array[i]);
    }
    for (int i = 0; i < array_size - 1; i++)
    {
        int p = i;
        int min = int_array[i];
        for (int j = i + 1; j < array_size; j++)
        {
            if (int_array[j] < min)
            {
                p = j;
                min = int_array[j];
            }
        }
        if (p != i)
        {
            int t = int_array[i];
            int_array[i] = min;
            int_array[p] = t;
        }
    }
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", int_array[i]);
    }
}