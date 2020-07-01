#include <iostream>
using namespace std;
int judge(int num)
{
    int atom = 1;
    for (int i = 0; i < 8; i++)
    {
        if (atom == num)
        {
            return 1;
        }
        atom <<= 1;
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    int dim;
    int dimn = 1;
    cin>>dim;
    for (int i = 0; i < dim; i++)
    {
        dimn *= 2;
    }
    int *cube = new int(dimn);
    for (int i = 0; i < dimn; i++)
    {
        cin >> cube[i];
    }
    for (int i = 0; i < dimn; i++)
    {
        for (int j = 0; j < dimn; j++)
        {
            cout << judge(cube[i] ^ cube[j]);
            if (j != dimn - 1)
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
}
