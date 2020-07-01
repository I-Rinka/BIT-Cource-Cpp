#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
int visited[1000];
int match[1000];
struct Student
{
    int Height;
    string Sex;
    string Music;
    string Spot;
};
int DFS(vector<vector<int>> &GraphX, int x, int nowY)
{
    for (int i = 0; i < GraphX[x].size(); i++)
    {
        if (!visited[GraphX[x][i]] && GraphX[x][i] != nowY)
        {
            visited[GraphX[x][i]] = 1;
            if (!match[GraphX[x][i]] || DFS(GraphX, match[GraphX[x][i]] - 1, GraphX[x][i]))
            {
                match[i] = x + 1;
                return 1;
            }
        }
    }
    return 0;
}
void GetAns()
{
    int n;
    cin >> n;
    Student *STUDENTS = new Student[n];
    vector<Student> F;
    vector<Student> M;
    for (int i = 0; i < n; i++)
    {
        cin >> STUDENTS[i].Height >> STUDENTS[i].Sex >> STUDENTS[i].Music >> STUDENTS[i].Spot;
        if (STUDENTS[i].Sex == "F")
        {
            F.push_back(STUDENTS[i]);
        }
        else
        {
            M.push_back(STUDENTS[i]);
        }
    }
    if (M.empty() || F.empty())
    {
        cout << n;
        return;
    }
    delete[] STUDENTS;

    vector<vector<int>> GraphM;
    GraphM.resize(M.size());
    for (int i = 0; i < F.size(); i++)
    {
        for (int j = 0; j < M.size(); j++)
        {
            if (abs(F[i].Height - M[j].Height) <= 40 && F[i].Spot != M[j].Spot && F[i].Music == M[j].Music) //连边
            {
                GraphM[j].push_back(i);
            }
        }
    }
    int num = 0;
    for (int i = 0; i < GraphM.size(); i++)
    {
        memset(visited, 0, 1000 * sizeof(int));
        num += DFS(GraphM, i, -1);
    }
    cout << (n)-num << endl;
}
int main(int argc, char const *argv[])
{
    int round;
    cin >> round;
    for (int i = 0; i < round; i++)
    {
        GetAns();
        memset(match, 0, sizeof(match));
    }
    return 0;
}
