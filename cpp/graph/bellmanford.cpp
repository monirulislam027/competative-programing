#include <bits/stdc++.h>
using namespace std;
const int VERTEX_COUNT = 1e3;
vector<pair<int, int>> adList[VERTEX_COUNT];
int dis[VERTEX_COUNT];
class Edge
{

public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<Edge> edgeList;
    while (edges--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edgeList.push_back(Edge(a, b, c));
    }

    for (int i = 0; i < vertex; i++)
    {
        dis[i] = INT_MAX;
    }

    int src;
    cin >> src;
    dis[src] = 0;
    for (int i = 0; i < vertex; i++)
    {
        for (Edge ed : edgeList)
        {
            if (dis[ed.u] < INT_MAX && dis[ed.u] + ed.c < dis[ed.v])
            {
                dis[ed.v] = ed.c + dis[ed.u];
            }
        }
    }
    bool cycle = false;
    for (Edge ed : edgeList)
    {
        if (dis[ed.u] < INT_MAX && dis[ed.u] + ed.c < dis[ed.v])
        {
            cycle = true;
            dis[ed.v] = ed.c + dis[ed.u];
        }
    }
    if (!cycle)
    {

        for (int i = 0; i < vertex; i++)
        {
            cout << i << " => " << dis[i] << endl;
        }
    }

    return 0;
}