#include <bits/stdc++.h>

using namespace std;

int main()
{
    queue<string> qu;

    int n;
    cin >> n;
    int cmd;
    string name;
    for (int i = 0; i < n; i++)
    {
        cin >> cmd;
        if (cmd)
        {
            if (qu.empty())
            {
                cout << "Invalid" << endl;
                continue;
            }

            cout << qu.front() << endl;
            qu.pop();
            continue;
        }

        cin >> name;
        qu.push(name);
    }

    return 0;
}
