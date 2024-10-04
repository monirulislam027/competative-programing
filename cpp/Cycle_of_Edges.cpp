#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int par[N];
int dsu_size[N];
int level[N];

void dsu_init(int n)
{
    for (int i = 1; i <= n; i++)
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
    // Write your code here
    int n, e;
    cin >> n >> e;
    dsu_init(n);
    int cnt = 0;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int parent1 = dsu_find(a);
        int parent2 = dsu_find(b);

        if (parent1 == parent2)
        {
            cnt++;
            continue;
        }
        dsu_union_by_size(a, b);
    }

    cout << cnt;

    return 0;
}
