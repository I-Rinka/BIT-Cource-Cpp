#include <iostream>
using namespace std;
class BusinessTraveler
{
private:
    string name;
    string page;

public:
    BusinessTraveler(string name, string page)
    {
        this->name = name;
        this->page = page;
    }
    /*
    BusinessTraveler(BusinessTraveler &other)
    {
        this->name = other.name;
        this->page = other.page;
    }*/
    friend ostream &operator<<(ostream &o, BusinessTraveler &bt);
};
ostream &operator<<(ostream &o, BusinessTraveler &bt)
{
    o << bt.name << '\n'
      << bt.page << endl;
    return o;
}

int main(int argc, char const *argv[])
{
    BusinessTraveler b("Joe BusinessMan", "Pager 1");
    cout << b;
    BusinessTraveler b2(b);
    cout << b2;
    BusinessTraveler b3("Joe BusinessMan", "Pager 2");
    cout << &b3 << endl;
    b2 = b3;
    cout << b2;
    cout << &b2 << endl;
    cout << &b3 << endl;
    return 0;
}
