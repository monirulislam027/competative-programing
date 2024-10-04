#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll N = 1e5 + 5;
ll par[N];
ll dsu_size[N];
ll level[N];

void dsu_init(ll n)
{
    for (ll i = 1; i <= n; i++)
    {
        par[i] = -1;
        dsu_size[i] = 1;
        level[i] = 0;
    }
}

ll dsu_find(ll node)
{
    if (par[node] == -1)
        return node;
    ll parent = dsu_find(par[node]);
    par[node] = parent;
    return parent;
}

void dsu_union(ll node1, ll node2)
{
    ll parent1 = dsu_find(node1);
    ll parent2 = dsu_find(node2);
    par[parent2] = parent1;
}

void dsu_union_by_size(ll node1, ll node2)
{
    ll parent1 = dsu_find(node1);
    ll parent2 = dsu_find(node2);
    if (dsu_size[parent1] > dsu_size[parent2])
    {
        par[parent2] = parent1;
        dsu_size[parent1] += dsu_size[parent2];
    }
    else
    {
        par[parent1] = parent2;
        dsu_size[parent2] += dsu_size[parent1];
    }
}

class Edge
{
public:
    ll u, v, c;
    Edge(ll u, ll v, ll c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}

int main()
{
    // Write your code here
    ll n, e;
    cin >> n >> e;
    dsu_init(n);
    vector<Edge> edgeList;
    while (e--)
    {
        ll u, v;
        long long c;
        cin >> u >> v >> c;
        if (u == v)
            continue;
        edgeList.push_back(Edge(u, v, c));
        edgeList.push_back(Edge(v, u, c));
    }

    sort(edgeList.begin(), edgeList.end(), cmp);
    ll totalCost = 0;

    for (auto c : edgeList)
    {
        ll parent1 = dsu_find(c.u);
        ll parent2 = dsu_find(c.v);

        if (parent1 == parent2)
            continue;
        dsu_union_by_size(c.u, c.v);

        totalCost += c.c;
    }
    ll parent = dsu_find(edgeList[0].u);

    bool v = true;
    for (ll i = 1; i <= n; i++)
    {
        ll p = dsu_find(i);
        if (p != parent)
        {
            v = false;
            break;
        }
    }

    cout << (!v ? -1 : totalCost);

    return 0;
}
