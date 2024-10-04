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
    for (int child : mat[src])
    {
        if (vis[child] == true && pathVis[src] != child)
        {
            ans = true;
        }
        if (vis[child] == false)
        {
            pathVis[child] = src;
            dfs(child);
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(pathVis, -1, sizeof(pathVis));
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