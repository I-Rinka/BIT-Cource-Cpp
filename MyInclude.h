#include <iostream>
using namespace std;
void printNumberSystem(int i)
{
    cout << hex << i << '\n'
         << dec << i << '\n'
         << oct << i << endl;
}