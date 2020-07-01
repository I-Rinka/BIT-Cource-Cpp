#include <vector>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<vector<int>> T;
    T.resize(1000);
    T[1].push_back(1);
    cout
        << T.size() << endl;
    return 0;
}
