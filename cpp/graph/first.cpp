#include <bits/stdc++.h>
using namespace std;
const int VERTEX_COUNT = 1e3;
int gr[VERTEX_COUNT][VERTEX_COUNT];
vector<int> adList[VERTEX_COUNT];
bool visited[VERTEX_COUNT];
int levels[VERTEX_COUNT];
int parents[VERTEX_COUNT];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    levels[src] = 0;

    while (!q.empty())
    {
        int parent = q.front();

        q.pop();

        for (int child : adList[parent])
        {
            if (visited[child] == false)
            {
                q.push(child);
                visited[child] = true;
                levels[child] = levels[parent] + 1;
                parents[child] = parent;
            }
        }
    }
}

int main()
{

    int v, e;
    cin >> v >> e;

    memset(gr, 0, sizeof(gr));
    memset(adList, 0, sizeof(adList));
    memset(visited, false, sizeof(visited));
    memset(levels, -1, sizeof(levels));
    memset(parents, -1, sizeof(parents));

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        gr[a][b] = 1;
        adList[a].push_back(b);
    }
    int src, target;
    cin >> src >> target;
    bfs(src);

    vector<int> path;

    int x = target;
    for (int i = 0; i < v; i++)
    {
        // cout << i << " " << parents[i] << endl;
    }

    while (x != -1)
    {
        path.push_back(x);
        x = parents[x];
    }
    reverse(path.begin(), path.end());
    for (int p : path)
    {
        cout << p << " ";
    }

    return 0;
}