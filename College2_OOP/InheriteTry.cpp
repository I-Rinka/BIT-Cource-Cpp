#include <iostream>
using namespace std;
class parent
{
private:
    char *str;
    int number;

public:
    parent()
    {
        str = (char *)malloc(sizeof("NULL"));
        char *temp = "NULL";
        for (int i = 0; i < 5; i++)
        {
            str[i] = temp[i];
        }
        number = 5;
    }
    parent(char *temp)
    {
        for (int i = 0; i < 10000; i++)
        {
            if (temp[i] == 0)
            {
                this->number = i + 1;
                break;
            }
        }
        this->str = (char *)malloc(sizeof(char) * number);
        for (int i = 0; i < number; i++)
        {
            this->str[i] = temp[i];
        }
    }
    parent(const parent &other)
    {
        new (this) parent(other.str);
    }
    friend ostream &operator<<(ostream &out, parent &temp)
    {
        for (int i = 0; i < temp.number; i++)
        {
            out << temp.str[i];
        }

        return out;
    }
};
class A : public parent
{
public:
    A() : parent()
    {
    }
    A(char *temp) : parent(temp)
    {
    }
    A(const A &Other) : parent(Other)
    {
    }
};
int main()
{
    A S("fucker");
    // cout << S;
    A B(S);
    cout << B;
}