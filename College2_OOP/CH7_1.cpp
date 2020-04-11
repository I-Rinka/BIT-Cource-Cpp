#include <iostream>
using namespace std;
class Employee
{
public:
    char name[20];
    int salary;
    Employee(const char *name)
    {
        for (int i = 0; i < 20; i++)
        {
            this->name[i] = name[i];
            if (name[i] == 0)
                break;
        }
    }
    virtual int monthGet(int monthSales) = 0;
};
class Manager : virtual public Employee
{
public:
    Manager(const char *name) : Employee(name)
    {
        salary = 7000;
    }
    int monthGet(int monthSales)
    {
        return salary;
    }
};
class Salesman : virtual public Employee
{
public:
    Salesman(const char *name) : Employee(name)
    {
    }
    int monthGet(int monthSales)
    {
        return 0.05 * monthSales;
    }
};
class Technician : virtual public Employee
{
public:
    Technician(const char *name) : Employee(name)
    {
    }
    int monthGet(int workHours)
    {
        return 100 * workHours;
    }
};
class SalesManager : public Manager, public Salesman
{
public:
    SalesManager(const char *name) : Manager(name), Salesman(name), Employee(name)
    {
        salary = 4000;
    }
    int monthGet(int monthSales)
    {
        return salary + Salesman::monthGet(monthSales);
    }
};
int main()
{
    SalesManager SM("SM");
    Technician TC("TC");
    Salesman SA("SA");
    Manager MG("MG");
    int monthS;
    int workH;
    for (int i = 1; i < 13; i++)
    {
        cout << "@ month " << i << " input sales volume:" << endl;
        cin >> monthS;
        cout << "intput work hours:" << endl;
        cin >> workH;
        cout << "Technician " << TC.name << " Got " << TC.monthGet(workH) << endl;
        cout << "Salesman " << SA.name << " Got " << SA.monthGet(monthS) << endl;
        cout << "Manager " << MG.name << " Got " << MG.monthGet(monthS) << endl;
        cout << "Sales Manager " << SM.name << " Got " << SM.monthGet(monthS) << endl;
    }
}