#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Task_Time
{
    int start_time;
    int end_time;
};
bool compare(const Task_Time A, const Task_Time B)//在乐学，compare函数不能使用引用
{
    if (A.start_time == B.start_time)
    {
        return A.end_time < B.end_time;
    }
    else
    {
        return A.start_time < B.start_time;
    }
}
struct end_time_compare
{
    bool operator()(Task_Time A, Task_Time B)
    {
        return A.end_time > B.end_time;
    }
};

int GetAns()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        return 0;
    }
    Task_Time *Time_table = new Task_Time[n];
    priority_queue<Task_Time, vector<Task_Time>, end_time_compare> Q; //小根堆,每次取最上
    for (int i = 0; i < n; i++)
    {
        cin >> Time_table[i].start_time >> Time_table[i].end_time;
    }
    sort(Time_table, Time_table + n, compare);
    Q.push(Time_table[0]);
    for (int i = 1; i < n; i++)
    {
        if (Time_table[i].start_time < Q.top().end_time)
        {
            Q.push(Time_table[i]);
        }
        else
        {
            Q.pop();
            Q.push(Time_table[i]);
        }
    }
    cout << Q.size() << endl;
    /*
    for (int i = 0; i < n; i++)
    {
        cout << Time_table[i].start_time << " " << Time_table[i].end_time << endl;
    }*/
    return n;
}
int main(int argc, char const *argv[])
{
    GetAns();
    return 0;
}
