#include <bits/stdc++.h>

using namespace std;
const int sz = 10000;
char mat[sz][sz];
bool vis[sz][sz];
vector<pair<int, int>> directions = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};
bool isFound = false;
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj, int di, int dj)
{
    queue<pair<int, int>> qu;
    qu.push({si, sj});
    vis[si][sj] = false;
    while (!qu.empty())
    {
        pair<int, int> par = qu.front();
        qu.pop();

        if (par.first == di && par.second == dj)
        {
            isFound = true;
            // break;
        }

        // cout << par.first << " " << par.second << endl;
        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + directions[i].first;
            int cj = par.second + directions[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false && mat[ci][cj] != '-')
            {
                qu.push({ci, cj});
                vis[ci][cj] = true;
            }
        }
    }
}

int main()
{
    // Write your code here

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char v;
            cin >> v;
            mat[i][j] = v;
        }
    }
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    memset(vis, false, sizeof(vis));
    bfs(si, sj, di, dj);
    cout << (isFound ? "YES" : "NO");

    return 0;
}
