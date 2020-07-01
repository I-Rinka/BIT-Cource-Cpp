#include <iostream>
using namespace std;
class KeepString
{
private:
    char *str;
    int number;

public:
    KeepString(const char *);
    ~KeepString();
    char *GetString();
};

KeepString::KeepString(const char *s)
{
    number = 0;
    while (1)
    {
        if (s[number] == 0)
        {
            break;
        }
        number++;
    }
    str = (char *)malloc(sizeof(char)*number);
    for (int i = 0; i < number; i++)
    {
        str[i] = s[i];
    }
}
char *KeepString::GetString()
{
    return str;
}
KeepString::~KeepString()
{
    free(str);
}

int main()
{
    KeepString KS("Internal String");
    const char *p = KS.GetString();
    cout << p << endl; // Output is:  Internal String
}
