#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    ll adj[v + 1][v + 1];

    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            adj[i][j] = INT_MAX;
            if (i == j)
                adj[i][j] = 0;
        }
    }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
    }

    for (int k = 1; k <= v; k++)
    {
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j])
                {

                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    int src, t;
    cin >> src >> t;
    for (int i = 0; i < t; i++)
    {
        int d, dw;
        cin >> d >> dw;
        if (adj[src][d] <= dw)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}