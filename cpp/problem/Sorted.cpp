#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Write your code here

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        set<long long> st;
        for (int i = 0; i < n; i++)
        {
            long long val;
            cin >> val;
            st.insert(val);
        }
        for (auto it = st.begin(); it != st.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}
