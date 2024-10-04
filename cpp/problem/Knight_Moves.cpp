#include <bits/stdc++.h>
using namespace std;
const int sz = 105;
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

int findSteps(int ki, int kj, int qi, int qj)
{
    int level[sz][sz];
    bool visited[sz][sz];
    vector<pair<int, int>> directions = {
        {-2, 1},
        {-1, 2},
        {-2, -1},
        {-1, -2},
        {1, 2},
        {2, 1},
        {2, -1},
        {1, -2},
    };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
            level[i][j] = -1;
        }
    }
    queue<pair<int, int>> q;
    q.push({ki, kj});
    visited[ki][kj] = true;
    level[ki][kj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        if (par.first == qi && par.second == qj)
            return level[qi][qj];
        for (auto chidDirection : directions)
        {
            int ci = par.first + chidDirection.first;
            int cj = par.second + chidDirection.second;
            if (valid(ci, cj) == true && visited[ci][cj] == false)
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
                level[ci][cj] = level[par.first][par.second] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        int ki, kj, qi, qj;
        cin >> n >> m >> ki >> kj >> qi >> qj;

        cout << findSteps(ki, kj, qi, qj) << endl;
    }

    return 0;
}