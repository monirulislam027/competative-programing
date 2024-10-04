#include <bits/stdc++.h>

using namespace std;

void printStack(stack<char> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    // Write your code here
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        stack<char> st;
        string str;
        cin >> str;
        for (auto c : str)
        {
            if (c == '1')
            {
                if (st.empty())
                    st.push(c);
                else
                {
                    if (st.top() == '0')
                        st.pop();
                    else
                        st.push(c);
                }
            }
            else
                st.push(c);
        }

        // printStack(st);
        cout << (st.empty() ? "YES" : "NO") << endl;
    }

    return 0;
}
