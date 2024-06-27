#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int mid = (n - 1) / 2;
    // top section
    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << "\\";
        for (int j = 0; j < ((2 * (mid - i)) - 1); j++)
        {
            cout << " ";
        }
        cout << "/";

        cout << endl;
    }
    // middle section
    for (int i = 0; i < mid; i++)
    {
        cout << " ";
    }

    cout << "X" << endl;

    // lower section
    for (int i = 1; i <= mid; i++)
    {
        for (int k = 0; k < mid - i; k++)
        {
            cout << " ";
        }

        cout << "/";
        for (int j = 0; j < (2 * i - 1); j++)
        {
            cout << " ";
        }

        cout << "\\";

        cout << endl;
    }

    return 0;
}

/*

\     /
 \   /
  \ /
   X
  / \
 /   \
/     \



*/