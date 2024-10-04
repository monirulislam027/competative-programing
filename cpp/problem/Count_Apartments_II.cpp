
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

int bfs(int si, int sj)
{
    int cnt = 1;
    queue<pair<int, int>> qu;
    qu.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    while (!qu.empty())
    {
        pair<int, int> par = qu.front();
        qu.pop();

        int parI = par.first, parJ = par.second;
        for (int i = 0; i < 4; i++)
        {
            int ci = parI + directions[i].first;
            int cj = parJ + directions[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false && mat[ci][cj] != '#')
            {
                qu.push({ci, cj});
                vis[ci][cj] = true;
                cnt++;
            }
        }
    }
    return cnt;
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
    vector<int> rooms;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] != '#' && vis[i][j] == false)
            {
                int r = bfs(i, j);
                rooms.push_back(r);
            }
        }
    }

    sort(rooms.begin(), rooms.end());

    for (int r : rooms)
    {
        cout << r << " ";
    }
    if (rooms.size() == 0)
    {
        cout << 0;
    }
    return 0;
}
