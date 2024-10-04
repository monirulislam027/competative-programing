#include <bits/stdc++.h>

using namespace std;
const int sz = 1e3 + 5;
int row, col;
char gird[sz][sz];
pair<int, int> parents[sz][sz];
bool vis[sz][sz];
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < row && j < col;
}

bool isFound = false;
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    bool isFound = false;
    while (!q.empty())
    {
        if (isFound)
            break;
        auto p = q.front();
        q.pop();
        int pi = p.first;
        int pj = p.second;
        for (int i = 0; i < 4; i++)
        {
            int ci = pi + directions[i].first;
            int cj = pj + directions[i].second;
            if (gird[ci][cj] == 'D')
            {
                parents[ci][cj] = {pi, pj};
                isFound = true;
                break;
            }
            if (valid(ci, cj) && !vis[ci][cj] && gird[ci][cj] != '#')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                parents[ci][cj] = {pi, pj};
            }
        }
    }
}

int main()
{
    // Write your code here

    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            char v;
            cin >> v;
            gird[i][j] = v;
        }
    }
    memset(vis, false, sizeof(vis));
    memset(parents, -1, sizeof(parents));
    int di, dj;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            if (gird[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
            if (gird[i][j] == 'R')
            {

                bfs(i, j);
            }
        }
    }

    int i = di,
        j = dj;

    while (1)
    {
        auto p = parents[i][j];
        int pi = p.first, pj = p.second;
        if (pi == -1 || pj == -1)
            break;
        if (gird[pi][pj] == '.')
            gird[pi][pj] = 'X';
        i = pi;
        j = pj;
        // break;
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            cout << gird[i][j];
        }
        cout << endl;
    }

    return 0;
}
