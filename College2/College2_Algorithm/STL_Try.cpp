#include<vector>
#include<iostream>
using namespace std;
int main()
{
    vector<vector<double>>obj(5,vector<double>(6));
    cout<<obj.size()<<endl<<obj[0].size()<<endl;
}