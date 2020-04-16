#include <iostream>
#include <sstream> // "String streams"
#include <cstring>
using namespace std;
template <typename A, int limit>
class Array
{
public:
    int interger[limit];
    int &operator[](int i)
    {
        if (i > limit)
        {
            cout << "out of length" << endl;
            return interger[0];
        }
        else
            return interger[i];
    }
    friend ostream &operator<<(ostream &os, const Array<A, limit> &ia)
    {
        for (int i = 0; i < limit; i++)
        {
            os << ia.interger[i] << endl;
        }
        return os;
    };
    friend istream &operator>>(istream &is, Array<A, limit> &ia)
    {
        for (int i = 0; i < limit; i++)
        {
            is >> ia.interger[i];
        }
        return is;
    };
};

int main()
{
    stringstream input("47 34 56 92 103");
    Array<int, 5> a;
    input >> a;
    a[4] = -1; // Use overloaded operator[]
    cout << a;
}
