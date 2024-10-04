#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int vis[100][100];
    int row, col, si, sj;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool valid(int i, int j)
    {
        if (i < 0 || j < 0 || i >= row || j >= col)
            return false;
        return true;
    }
    int bfs(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> qu;
        qu.push({si, sj});
        vis[si][sj] = true;
        int perimeterCount = 0;
        while (!qu.empty())
        {
            pair<int, int> par = qu.front();
            qu.pop();
            int childCount = 0;
            for (int i = 0; i < 4; i++)
            {
                int ci = par.first + directions[i].first;
                int cj = par.second + directions[i].second;
                if (valid(ci, cj) == true && grid[ci][cj] == 1)
                {
                    childCount++;
                    if (vis[ci][cj] == false)
                    {
                        qu.push({ci, cj});
                        vis[ci][cj];
                    }
                }
            }

            perimeterCount += 4 - childCount;
        }

        return perimeterCount;
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {
        row = grid.size();
        col = grid[0].size();
        bool isFound = false;
        for (int i = 0; i < row; i++)
        {
            if (isFound)
                break;
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] == false)
                {
                    isFound = true;
                    si = i;
                    sj = j;
                    break;
                }
            }
        }
        return bfs(grid);
    }
};