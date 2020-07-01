#include <iostream>
using namespace std;
class CSet
{
private:
    /* data */
    int size;
    int *member;

public:
    CSet()
    {
        this->size = 0;
        this->member = NULL;
    }
    CSet(int number)
    {
        this->size = 1;
        member = new (int);
        *member = number;
    }
    CSet(int *a, int length)
    {
        this->member = (int *)malloc(sizeof(int) * length);
        this->size = length;
        for (int i = 0; i < length; i++)
        {
            this->member[i] = a[i];
        }
    }
    CSet operator+(const CSet &other)
    {
        CSet NewSet;
        NewSet.size = this->size + other.size;
        NewSet.member = (int *)malloc(sizeof(int) * NewSet.size);
        for (int i = 0; i < this->size; i++)
        {
            NewSet.member[i] = this->member[i];
        }
        for (int i = 0; i < other.size; i++)
        {
            NewSet.member[i + this->size] = other.member[i];
        }
        return NewSet;
    }
    void operator=(const CSet &Set)
    {
        free(this->member);
        this->size = Set.size;
        this->member = (int *)malloc(sizeof(int) * Set.size);
        for (int i = 0; i < this->size; i++)
        {
            this->member[i] = Set.member[i];
        }
    }
    ~CSet()
    {
        free(this->member);
    }
    friend ostream &operator<<(ostream &output, const CSet &other)
    {
        output << '[';
        for (int i = 0; i < other.size; i++)
        {
            output << '[' << other.member[i] << ']';
        }
        output << ']' << endl;
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