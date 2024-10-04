#include <bits/stdc++.h>
using namespace std;
const int sz = 1e5 + 5;
vector<int> mat[sz];
int pathVis[sz];
bool vis[sz];
bool ans;

void bfs(int src)
{
    queue<int> qu;
    qu.push(src);
    vis[src] = true;
    while (!qu.empty())
    {
        int parent = qu.front();
        qu.pop();

        for (int child : mat[parent])
        {
            if (vis[child] == true && pathVis[parent] != child)
            {
                ans = true;
            }
            if (vis[child] == false)
            {
                qu.push(child);
                vis[child] = true;
                pathVis[child] = parent;
            }
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
            bfs(i);
        }
    }
    if (ans)
        cout << "true";
    else
        cout << "false";

    return 0;
}