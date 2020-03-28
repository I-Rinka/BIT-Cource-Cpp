#include <iostream>
using namespace std;
class CSet
{
private:
    /* data */
    int size;
    int *member;

public:
    CSet();
    CSet(int);
    CSet(int *, int);
    CSet operator+(const CSet &other)
    {
        CSet NewSet;
        NewSet.size = this->size + other.size;
        NewSet.member = (int *)malloc(sizeof(int) * NewSet.size);
        for (int i = 0; i < this->size; i++)
        {
        }
    }
    ~CSet();
    friend ostream &operator<<(ostream &output, const CSet &other)
    {
        output << '[';
        for (int i = 0; i < other.size; i++)
        {
            output << ' ' << '[' << other.member[i] << ']';
        }
        output << ' ' << ']';
        return output;
    }
};
int main()
{
    int a[] = {1, 3, 5, 7, 6, 4, 2};
    CSet S1, S2(a, 7);
    S1 = S2 + 8;
    CSet S3 = S1 + S2;
    cout << S1 << S2 << endl;
}