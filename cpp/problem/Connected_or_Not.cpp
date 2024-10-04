#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n, e;
    cin >> n >> e;

    int mat[n][n];
    memset(mat, 0, sizeof(mat));
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        mat[i][i] = 1;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a >= n || b >= n)
        {
            cout << "NO" << endl;
        }
        if (mat[a][b] == 1)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}