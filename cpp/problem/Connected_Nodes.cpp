#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n, e;
    cin >> n >> e;

    vector<int> mat[n];
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    int q;
    cin >> q;

    while (q--)
    {
        int t;
        cin >> t;
        if (mat[t].size() <= 0)
            cout << "-1";
        sort(mat[t].begin(), mat[t].end(), greater<int>());

        for (auto child : mat[t])
        {
            cout << child << " ";
        }
        cout << endl;
    }

    return 0;
}