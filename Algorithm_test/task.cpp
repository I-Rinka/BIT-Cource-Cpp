#include <queue>
#include <iostream>
using namespace std;
const int maxN = 10000 + 10;
int n;
struct task
{
    int ddl;
    int punish;
};
task Tasks[maxN];
task HashQueue[maxN];
queue<task> FailedTask;
int visited[maxN];
struct punish_compare
{
    bool operator()(task A, task B)
    {
        return A.punish < B.punish;
    }
};
bool VoidSearch(int start, task &fuck) //往前找一个空位
{
    bool judge = false;
    for (int i = start - 1; i >= 0; i--)
    {
        if (!visited[i])
        {
            HashQueue[i] = fuck;
            visited[i] = true;
            judge = true;
            break;
        }
    }
    return judge;
}
void input()
{
    priority_queue<task, vector<task>, punish_compare> BigTask;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> Tasks[i].ddl;
        Tasks[i].ddl--;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> Tasks[i].punish;
        BigTask.push(Tasks[i]);
    }
    for (int i = 0; i < n; i++)
    {
        task temp = BigTask.top();
        BigTask.pop();
        if (visited[temp.ddl])
        {
            if (!VoidSearch(temp.ddl, temp))
            {
                FailedTask.push(temp);
            }
        }
        else
        {
            HashQueue[temp.ddl] = temp;
            visited[temp.ddl] = true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            HashQueue[i] = FailedTask.front();
            FailedTask.pop();
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (HashQueue[i].ddl < i)
        {
            ans += HashQueue[i].punish;
        }
    }
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    input();
    return 0;
}
