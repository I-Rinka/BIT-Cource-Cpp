#include <iostream>
using namespace std;
class Traveler
{
private:
    char *Str;
    int number = 0;

public:
    char *Name()
    {
        return Str;
    }
    Traveler(const char *str)
    {
        while (1)
        {
            number++;
            if (str[number] == 0)
            {
                break;
            }
        }
        this->Str = (char *)malloc(sizeof(char) * number);
        for (int i = 0; i <= number; i++)
        {
            this->Str[i] = str[i];
        }
    }
    Traveler(const Traveler &t)
    {
        Traveler(t.Str);
    }
    ~Traveler()
    {
        // free(this->Str);
    }
    void operator=(Traveler &other)
    {
        other.Str = (char *)malloc(sizeof(char) * this->number);
        for (int i = 0; i <= number; i++)
        {
            other.Str[i] = this->Str[i];
        }
    }
};
class Pager
{
private:
    char *Str;
    int number = 0;

public:
    Pager(const char *str)
    {
        int number = 0;
        while (1)
        {
            number++;
            if (str[number] == 0)
            {
                break;
            }
        }
        this->Str = (char *)malloc(sizeof(char) * number);
        for (int i = 0; i <= number; i++)
        {
            this->Str[i] = str[i];
        }
    }
    ~Pager()
    {
        // free(this->Str);
    }
    void operator=(Pager &other)
    {
        other.Str = (char *)malloc(sizeof(char) * this->number);
        for (int i = 0; i <= number; i++)
        {
            other.Str[i] = this->Str[i];
        }
    }
    friend ostream &operator<<(ostream &out, Pager &temp)
    {
        out
            << temp.Str;
        return out;
    }
};
class BusinessTraveler : public Traveler
{
public:
    Pager A;
    BusinessTraveler() : Traveler("NULL"), A("NULL")
    {
    }
    BusinessTraveler(const char *TravelerName, const char *PageName) : Traveler(TravelerName), A(PageName)
    {
    }
    BusinessTraveler(BusinessTraveler &t) : Traveler(t.Name()), A(t.A)
    {
    }
    friend ostream &operator<<(ostream &out, BusinessTraveler &temp)
    {
        out << temp.Name() << '\n'
            << temp.A
            << endl;
        return out;
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
