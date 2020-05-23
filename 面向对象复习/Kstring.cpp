#include <iostream>
using namespace std;
class Myclass
{
private:
    /* data */
public:
    int d;
    Myclass();

    ~Myclass();
};

Myclass::Myclass()
{
}

Myclass::~Myclass()
{
}

int main(int argc, char const *argv[])
{
    int p[20];
    Myclass *m = new Myclass[20];
    m->d = 10;

    return 0;
}
