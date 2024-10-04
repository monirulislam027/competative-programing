#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int par[N];
int dsu_size[N];
int level[N];

void dsu_init(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        dsu_size[i] = 1;
        level[i] = 0;
    }
}

int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int parent = dsu_find(par[node]);
    par[node] = parent;
    return parent;
}

void dsu_union(int node1, int node2)
{
    int parent1 = dsu_find(node1);
    int parent2 = dsu_find(node2);
    par[parent2] = parent1;
}
void dsu_union_by_level(int node1, int node2)
{
    int parent1 = dsu_find(node1);
    int parent2 = dsu_find(node2);
    if (level[parent1] > level[parent2])
    {
        par[parent2] = parent1;
    }
    else if (level[parent2] > level[parent1])
    {
        par[parent1] = parent2;
    }
    else
    {
        par[parent1] = parent2;
        level[parent2]++;
    }
}
void dsu_union_by_size(int node1, int node2)
{
    int parent1 = dsu_find(node1);
    int parent2 = dsu_find(node2);
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

int main()
{
    int v, e;
    cin >> v >> e;
    dsu_init(v);

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dsu_union_by_level(u, v);
    }

    for (int i = 0; i < v; i++)
    {
        cout << par[i] << endl;
    }
    return 0;
}
