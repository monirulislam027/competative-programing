#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 1e4;
vector<int> mat[MAX_SIZE];
int bfs(int src, int target, int v)
{
    // cout << "src " << src << " |  bfs " << endl;
    bool visited[v];
    int parents[v];
    memset(visited, false, sizeof(parents));
    memset(parents, -1, sizeof(parents));
    queue<int> qu;
    qu.push(src);
    visited[src] = true;

    while (!qu.empty())
    {
        int parent = qu.front();
        qu.pop();

        for (int child : mat[parent])
        {
            if (visited[child] == false)
            {
                qu.push(child);
                visited[child] = true;
                parents[child] = parent;
            }
        }
    }

    int count = 0;
    int x = target;
    for (int i = 0; i < v + 1; i++)
    {
        cout << i << "=>" << parents[i] << endl;
    }

    while (x != -1)
    {
        x = parents[x];
        count++;
    }

    return count - 1;
};

int main()
{

    int v, e;
    cin >> v >> e;

    memset(mat, 0, sizeof(mat));

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        mat[a].push_back(b);
        mat[b].push_back(a);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int src, target;
        cin >> src >> target;

        int result = bfs(src, target, v);

        cout << "result => " << result << endl;
        cout << endl
             << endl;
    }

    return 0;
}