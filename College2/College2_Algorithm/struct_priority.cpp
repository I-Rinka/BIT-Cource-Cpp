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
    friend ostream &operator<<(ostream &os, const QQ &other)
    {
        os << other.num;
        return os;
    }
};
priority_queue<QQ, vector<QQ>, less<QQ>> BQ;
int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; i++)
    {
        int t = rand();
        cout << t << endl;
        QQ *f = new QQ;
        f->num = t;
        BQ.push(*f);
    }
    while (!BQ.empty())
    {
        cout << BQ.top() << endl;
        BQ.pop();
    }

    return 0;
}
