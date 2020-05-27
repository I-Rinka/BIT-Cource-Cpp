#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<int> num_stack;
int priority(char c)
{
    if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '-' || c == '+')
    {
        return 1;
    }
    else if (c == '\n')
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int main(int argc, char const *argv[])
{
    int dv0_judge = 0;
    int error_judge = 0;
    while (1)
    {
        char c = getchar();
        if (c == '\n' || dv0_judge || error_judge)
        {
            if (dv0_judge)
            {
                cout << "DIV0!" << endl;
            }
            else if (error_judge)
            {
                cout << "ERROR!" << endl;
            }
            else
                cout << num_stack.top() << endl;
            break;
        }
        if (c >= '0' && c <= '9')
        {
            num_stack.push((int)c - '0');
        }
        else
        {
            if (num_stack.size() < 2)
            {
                error_judge = 1;
            }
            else
            {
                int num1 = num_stack.top();
                num_stack.pop();
                int num2 = num_stack.top();
                num_stack.pop();
                if (c == '+')
                {
                    num_stack.push(num1 + num2);
                }
                else if (c == '-')
                {

                    num_stack.push(num2 - num1);
                }
                else if (c == '*')
                {

                    num_stack.push(num1 * num2);
                }
                else if (c == '/')
                {
                    if (num1 == 0)
                    {
                        dv0_judge = 1;
                    }
                    else
                        num_stack.push(num2 / num1);
                }
                else
                    error_judge = 1;
            }
        }
    }
}