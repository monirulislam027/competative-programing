#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const long long INF = LONG_LONG_MAX;
int main()
{
    ll v, e;
    cin >> v >> e;

    ll adj[v + 5][v + 5];

    for (ll i = 1; i <= v; i++)
    {
        for (ll j = 1; j <= v; j++)
        {
            adj[i][j] = i != j ? INF : 0;
        }
    }

    while (e--)
    {
        ll a, b;
        ll c;
        cin >> a >> b >> c;
        if (adj[a][b] == INF || adj[a][b] >= c)
            adj[a][b] = c;
    }

    for (ll k = 1; k <= v; k++)
    {
        for (ll i = 1; i <= v; i++)
        {
            for (ll j = 1; j <= v; j++)
            {
                if (adj[i][k] != INF && adj[k][j] != INF && (adj[i][k] + adj[k][j]) < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll src, des;
        cin >> src >> des;
        if (adj[src][des] == INF)
            cout << -1 << endl;
        else
            cout << adj[src][des] << endl;
    }

    return 0;
}