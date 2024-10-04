#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<int> st1;
    queue<int> qu1;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        st1.push(val);
    }

    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        qu1.push(val);
    }

    bool flag = true;
    if (n != m)
    {
        flag = false;
    }
    else
    {
        while (!st1.empty())
        {
            if (st1.top() == qu1.front())
            {
                st1.pop();
                qu1.pop();
            }
            else
            {
                flag = false;
                break;
            }
        }
    }
    flag ? cout << "YES" : cout << "NO";
    cout << endl;

    return 0;
}
