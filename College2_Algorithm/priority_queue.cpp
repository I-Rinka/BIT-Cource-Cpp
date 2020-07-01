#include <queue>
#include <iostream>
using namespace std;
priority_queue<int, vector<int>, less<int>> BQ;//大根堆
int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; i++)
    {
        int t = rand();
        cout << t<<endl;
        BQ.push(t);
    }
    while (!BQ.empty())
    {
        cout << BQ.top() << endl;
        BQ.pop();
    }
    return 0;
}
