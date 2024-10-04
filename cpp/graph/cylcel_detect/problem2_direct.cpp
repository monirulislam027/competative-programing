#include <bits/stdc++.h>
using namespace std;
const int sz = 1e5 + 5;
vector<int> mat[sz];
int pathVis[sz];
bool vis[sz];
bool ans;

void dfs(int src)
{
    vis[src] = true;
    pathVis[src] = true;
    for (int child : mat[src])
    {
        if (pathVis[child])
        {
            ans = true;
        }
        if (vis[child] == false)
        {
            dfs(child);
        }
    }
    pathVis[src] = false;
}

int main()
{
    int v, e;
    cin >> v >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
    }

    memset(vis, false, sizeof(vis));
    memset(pathVis, false, sizeof(pathVis));
    ans = false;

    for (int i = 0; i < v; i++)
    {
        if (vis[i] == false)
        {
            dfs(i);
        }
    }
    cout << (ans ? "true" : "false");

    return 0;
}