#include <bits/stdc++.h>

using namespace std;

class cmp
{
public:
    bool operator()(long long a, long long b)
    {
        return a > b;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Write your code here

    int n;
    cin >> n;

    priority_queue<long long, vector<long long>, cmp> pq;

    for (int i = 0; i < n; i++)
    {
        long long val;
        cin >> val;
        pq.push(val);
    }

    int q;
    cin >> q;
    for (int j = 0; j < q; j++)
    {
        int cm;
        cin >> cm;
        if (cm == 0)
        {
            long long val;
            cin >> val;
            pq.push(val);
            if (pq.empty())
                cout << "Empty" << endl;
            else
                cout << pq.top() << endl;
        }
        else if (cm == 1)
        {
            if (pq.empty())
                cout << "Empty" << endl;
            else
                cout << pq.top() << endl;
        }
        else if (cm == 2)
        {
            if (!pq.empty())
                pq.pop();
            if (pq.empty())
                cout << "Empty" << endl;
            else
                cout << pq.top() << endl;
        }
    }

    return 0;
}
