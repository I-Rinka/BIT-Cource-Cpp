#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> V;
bool compare(int &a, int &b)
{
    return a > b;
}
int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; i++)
    {
        int t = rand();
        cout << t << endl;
        V.push_back(t);
    }
    sort(V.begin(), V.end(), compare);
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i] << endl;
    }

    return 0;
}
