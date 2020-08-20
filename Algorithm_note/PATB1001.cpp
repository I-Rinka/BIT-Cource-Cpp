#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int input;
    scanf("%d", &input);
    int count = 0;
    while (input != 1)
    {
        if (input % 2 == 0)
        {
            input = input / 2;
        }
        else
        {
            input = (3 * input + 1)/2;
        }
        count++;
    }
    printf("%d\n", count);
    return 0;
}
