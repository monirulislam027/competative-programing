#include <bits/stdc++.h>
using namespace std;
char a[20][20];
int n, m;
int level[20][20];
bool visited[20][20];
vector<pair<int, int>> directions = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void dfs(int si, int sj)
{

    cout << si << " " << sj << endl;
    visited[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = directions[i].first + si;
        int cj = directions[i].second + sj;
        if (valid(ci, cj) == true && visited[ci][cj] == false)
        {
            dfs(ci, cj);
        }
    }
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        // cout << par.first << " " << par.second << endl;
        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + directions[i].first;
            int cj = par.second + directions[i].second;
            if (valid(ci, cj) == true && visited[ci][cj] == false)
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
                level[ci][cj] = level[par.first][par.second] + 1;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    bfs(si, sj);
    cout << level[3][3];
    return 0;
}