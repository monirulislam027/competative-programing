#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const long long INF = LONG_LONG_MAX;
class Edge
{

public:
    ll c;
    int u, v;
    Edge(int u, int v, ll c)
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
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edgeList.push_back(Edge(a, b, c));
    }

    ll dis[vertex + 5];

    int src;
    cin >> src;

    for (int i = 1; i <= vertex; i++)
    {
        dis[i] = INF;
    }
    dis[src] = 0;
    for (int i = 1; i <= vertex; i++)
    {
        for (Edge ed : edgeList)
        {
            if (dis[ed.u] < INF && dis[ed.u] + ed.c < dis[ed.v])
            {
                dis[ed.v] = ed.c + dis[ed.u];
            }
        }
    }

    bool cycle = false;
    for (Edge ed : edgeList)
    {
        if (dis[ed.u] < INF && dis[ed.u] + ed.c < dis[ed.v])
        {
            cycle = true;
            dis[ed.v] = ed.c + dis[ed.u];
        }
    }

    if (cycle)
        cout << "Negative Cycle Detected";
    else
    {
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
            int d;
            cin >> d;
            if (dis[d] == INF)
                cout << "Not Possible" << endl;
            else
                cout << dis[d] << endl;
        }
    }

    return 0;
}