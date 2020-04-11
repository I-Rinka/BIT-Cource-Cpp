#include <iostream>
using namespace std;
class Employee
{
public:
    char name[20];
    int salary;
    virtual int pay(int monthSales) = 0;
    Employee(const char *name)
    {
        for (int i = 0; i < 20; i++)
        {
            this->name[i] = name[i];
            if (name[i] == 0)
                break;
        }
    }
};
class Manager : virtual public Employee
{
public:
    Manager(const char *name) : Employee(name)
    {
        salary = 7000;
    }
    int pay(int monthSales)
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
    int pay(int monthSales)
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
    int pay(int workHours)
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
    int pay(int monthSales)
    {
        return salary + Salesman::pay(monthSales);
    }
};
int main()
{
    Employee *EM;
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
        EM = &SM;
        cout << EM->name << " Got " << EM->pay(workH) << endl;
        EM = &TC;
        cout << EM->name << " Got " << EM->pay(monthS) << endl;
        EM = &SA;
        cout << EM->name << " Got " << EM->pay(monthS) << endl;
        EM = &MG;
        cout << EM->name << " Got " << EM->pay(monthS) << endl;
        //运行类似java的接口，公共父类提供的虚函数，子类来具体实现
    }
}