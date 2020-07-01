#include <iostream>
#include <iostream>
#include <queue>
using namespace std;
struct QQ
{
    int num;
    bool operator<(const QQ &other) const
    {
        return this->num < other.num;
    }
    friend ostream &operator<<(ostream &os, QQ &other)
    {
        os << other.num;
        return os;
    }
};
vector<QQ> Q;
int main(int argc, char const *argv[])
{
    QQ *t = new QQ;
    t->num = 2;
    cout << *t << endl;
    Q.push_back(*t);
    cout << Q.front();
    return 0;
}
