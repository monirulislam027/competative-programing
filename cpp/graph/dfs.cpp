#include <bits/stdc++.h>
using namespace std;
const int VERTEX_COUNT = 1e3;
int gr[VERTEX_COUNT][VERTEX_COUNT];
vector<int> adList[VERTEX_COUNT];
bool visited[VERTEX_COUNT];
int levels[VERTEX_COUNT];
int parents[VERTEX_COUNT];

void dfs(int src)
{
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
    return 0;
}
