#include <iostream>
using namespace std;
class CArray
{
private:
    char *str;
    int length; // elements number
    int size;   // storage number
                // Other variables are here.
public:
    CArray(char *a);
    CArray(int t);
    ~CArray();
    void Copy(const char *t);
    char *c_str;
    // Member functions are here.
};
CArray::CArray(int t)
{
    this->size = t;
    this->str = new char[t + 1];
    c_str = str;
}
CArray::~CArray()
{
    delete[] this->str;
}
void CArray::Copy(const char *t)
{
    int i = 0;
    for (int i = 0; i < size; i++)
    {
        if (t[i] == 0)
        {
            break;
        }
        this->str[i] = t[i];
        
    }
    this->length = i;
}
int main()
{
    CArray arr(10);

    // “Hello world!” is stored in arr.
    arr.Copy("Hello world !");
    printf("%s", arr.c_str);
}
