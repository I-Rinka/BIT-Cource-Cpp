#include <iostream>
using namespace std;
class Traveler
{
private:
    char *Str;
    int number;

public:
    Traveler(const char *temp)
    {
        number = 0;
        for (int i = 0; i < 10000; i++)
        {
            if (temp[i] == 0)
            {
                number = i + 1;
                break;
            }
        }
        Str = (char *)malloc(sizeof(char) * number);
        for (int i = 0; i < number; i++)
        {
            Str[i] = temp[i];
        }
    }
    Traveler(const Traveler &Other)
    {
        new (this) Traveler(Other.Str);
    }
    ~Traveler()
    {
        free(Str);
    }
    friend ostream &operator<<(ostream &out, Traveler &temp)
    {
        for (int i = 0; i < temp.number; i++)
        {
            out << temp.Str[i];
        }
        return out;
    }
};
class Pager
{
private:
    char *Str;
    int number;

public:
    Pager(const char *temp)
    {
        number = 0;
        for (int i = 0; i < 10000; i++)
        {
            if (temp[i] == 0)
            {
                number = i + 1;
                break;
            }
        }
        Str = (char *)malloc(sizeof(char) * number);
        for (int i = 0; i < number; i++)
        {
            Str[i] = temp[i];
        }
    }
    Pager(const Pager &Other)
    {
        new (this) Pager(Other.Str);
    }
    ~Pager()
    {
        free(Str);
    }
    friend ostream &operator<<(ostream &out, Pager &temp)
    {
        for (int i = 0; i < temp.number; i++)
        {
            out << temp.Str[i];
        }
        return out;
    }
};
class BusinessTraveler : public Traveler
{
private:
    Pager pg;

public:
    BusinessTraveler(char *TravelerName, char *PagerName) : Traveler(TravelerName), pg(PagerName)
    {
    }
    BusinessTraveler() : Traveler("NULL"), pg("NULL")
    {
    }
    BusinessTraveler(const BusinessTraveler &Other) : Traveler(Other), pg(Other.pg)
    {
    }
    friend ostream &operator<<(ostream &os, BusinessTraveler &temp)
    {
        os << (Traveler &)temp << '\n'
           << temp.pg;
        return os;
    }
    void operator=(BusinessTraveler &Other)
    {
        new (this) BusinessTraveler(Other);
    }
};
int main()
{
    BusinessTraveler b1("Joe BusinessMan", "Pager 1");
    cout << b1 << endl;
    BusinessTraveler b2("Jane BusinessWoman", "Pager 2");
    cout << b2 << endl;
    BusinessTraveler b3;
    cout << b3 << endl;
    BusinessTraveler b4(b1);
    cout << b4 << endl;
    b3 = b2;
    cout << b3 << endl;
}
