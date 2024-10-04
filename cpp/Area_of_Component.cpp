#include <bits/stdc++.h>

using namespace std;
const int sz = 1e3 + 5;
int row, col;
char gird[sz][sz];
bool vis[sz][sz];
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < row && j < col;
}

int cnt = 0;
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    cnt++;
    for (auto d : directions)
    {
        int ci = si + d.first;
        int cj = sj + d.second;
        if (valid(ci, cj) && !vis[ci][cj] && gird[ci][cj] != '-')
        {
            dfs(ci, cj);
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
            vis[i][j] = false;
            char v;
            cin >> v;
            gird[i][j] = v;
        }
    }

    int minVal = INT_MAX;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            if (!vis[i][j] && gird[i][j] == '.')
            {
                cnt = 0;
                dfs(i, j);
                minVal = min(minVal, cnt);
            }
        }
    }
    cout << (minVal == INT_MAX ? -1 : minVal);

    return 0;
}
