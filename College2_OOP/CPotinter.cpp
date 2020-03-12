#include <iostream>
using namespace std;
class CPointer
{
private:
    int *p;

public:
    CPointer(int x);
    ~CPointer();
    void Copy(CPointer &t);
};
CPointer::CPointer(int x)
{
    this->p = new int(x);
}
CPointer::~CPointer()
{
    delete this->p;
}
void CPointer::Copy(CPointer &t)
{
    *(this->p) = *(t.p);
}
int main()
{
    CPointer p(10), q(20);
    q.Copy(p);
    printf("%p %p\n", &p, &q);