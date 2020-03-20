#include <iostream>
int num = 0;
class CSmart
{ //  Here is your code...
public:
    void Objects()
    {
        if (num > 1)
        {
            std::cout << " objects" << std::endl;
        }
        else
        {
            std::cout << " object" << std::endl;
        }
    };
    CSmart()
    {
        std::cout << ++num;
        Objects();
    };
    ~CSmart()
    {
        std::cout << --num;
        Objects();
    }
};
void DoSomething()
{
    CSmart s;
}
CSmart s1;
int main()
{
    CSmart s2;
    DoSomething();
    CSmart *s3 = new CSmart;
    delete s3;
}
