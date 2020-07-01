#include <iostream>
using namespace std;
class Vehicle
{
public:
    double distance;
    double weight;
    virtual double Fee() = 0;
    void GetDistance(double d) { distance = d; }
    void GetWeight(double w) { weight = w; }
    virtual ~Vehicle()
    {
        cout << "Vehicle" << endl;
    }
};
class AirPlane : public Vehicle
{
public:
    virtual double Fee()
    {
        return distance * 1.15 + weight * 1.05;
    }
    ~AirPlane()
    {
        cout << "AirPlane" << endl;
    }
};
class Ship : public Vehicle
{
public:
    virtual double Fee()
    {
        return distance * 1.05 + weight * 0.9;
    }
    ~Ship()
    {
        cout << "Ship" << endl;
    }
};
class Car : public Vehicle
{
public:
    virtual double Fee()
    {
        return distance * 1.2 + weight * 1.1;
    }
    ~Car()
    {
        cout << "Car" << endl;
    }
};
int main()
{
    Vehicle *v[3];
    v[0] = new AirPlane;
    v[1] = new Ship;
    v[2] = new Car;
    for (int i = 0; i < 3; i++)
    {
        double t;
        cin >> t;
        v[i]->GetDistance(t);
        cin >> t;
        v[i]->GetWeight(t);
        cout << v[i]->Fee() << endl;
        delete v[i]; //delete时只会执行基类的析构而不执行子类的析构？
    }
}