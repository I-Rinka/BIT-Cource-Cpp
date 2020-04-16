#include <iostream>
#include <sstream> // "String streams"
#include <cstring>
using namespace std;

/*
class Araray
{
    enum
    {
        sz = 5
    };
    int i[sz];

public:
    Arsray() { memset(i, 0, sz * sizeof(*i)); }
    int &operator[](int x)
    {
        require(x >= 0 && x < sz,
                "Array::operator[] out of range");
        return i[x];
    }
};*/
template <typename A, int B>
class Array
{
public:
    friend ostream &operator<<(ostream &os, const Array<A, B> &ia)
    {
        // for (int j = 0; j < ia.sz; j++)
        //     is >> ia.i[j];
        return os;
    };
    friend istream &operator>>(istream &is, Array<A, B> &ia)
    {
        // for (int j = 0; j < ia.sz; j++)
        //     is >> ia.i[j];
        return is;
    };
};

int main()
{
    stringstream input("47 34 56 92 103");
    // Array<int, 5> a;
    // input >> a;
    string temp;
    input >> temp;
    cout << temp;
    // a[4] = -1; // Use overloaded operator[]
    // cout << a;
}
