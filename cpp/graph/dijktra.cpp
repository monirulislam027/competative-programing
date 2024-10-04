#include <bits/stdc++.h>
using namespace std;
const int VERTEX_COUNT = 1e3;
vector<pair<int, int>> adList[VERTEX_COUNT];
int dis[VERTEX_COUNT];
class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
void dijktra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    q.push({src, 0});
    dis[src] = 0;

    while (!q.empty())
    {
        pair<int, int> parent = q.top();
        int vertex = parent.first, cost = parent.second;
        q.pop();

        for (auto child : adList[vertex])
        {
            int childVertex = child.first;
            int childCost = child.second;
            if (cost + childCost < dis[childVertex])
            {
                dis[childVertex] = cost + childCost;
                q.push({childVertex, dis[childVertex]});
            }
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adList[a].push_back({b, c});
        adList[b].push_back({a, c});
    }

    int src;
    cin >> src;
    for (int i = 0; i < v; i++)
    {
        dis[i] = INT_MAX;
    }

    dijktra(src);

    for (int i = 0; i < v; i++)
    {
        cout << i << " => " << dis[i] << endl;
    }

    return 0;
}