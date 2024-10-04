#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1000;
char mat[SIZE][SIZE];
bool vis[SIZE][SIZE];
int level[SIZE][SIZE];
int n, m;
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj)
{

        vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + directions[i].first;
        int cj = sj + directions[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false && mat[ci][cj] != '#')
        {
            dfs(ci, cj);
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

            cin >> mat[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] != '#' && vis[i][j] == false)
            {
                dfs(i, j);
                count++;
            }
        }
    }

    cout << count;

    return 0;
}
