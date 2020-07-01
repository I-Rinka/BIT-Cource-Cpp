#include <iostream>
using namespace std;
template <class T>
class MyArray
{
private:
    T *d; //数组指针
    int number;

public:
    MyArray(int number)
    {
        this->number = number;
        this->d = new T[number]; //分配内存，这里使用C++的方式
    }
    T &operator[](int number) //[]重载，返回类型使用T&是为了能实现赋值操作
    {
        if (number > this->number) //越界判断
        {
            cout << "数组越界!" << endl;
            return this->d[this->number];
        }
        return this->d[number];
    }
    ~MyArray()
    {
        delete[] this->d; //解除动态内存的占用
    }
    friend ostream &operator<<(ostream &o, MyArray &MA)//流输出重载
    {
        for (int i = 0; i < MA.number; i++)
        {
            o << MA[i] << ',';
        }
        return o;
    }
};

int main()
{
    MyArray<int> intArray(10); // 10 is the number of elements in intArray
    for (int i = 0; i < 10; i++)
        intArray[i] = i * i;
    cout << intArray << endl;
}
