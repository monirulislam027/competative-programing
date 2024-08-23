#include <bits/stdc++.h>
using namespace std;
int main()
{

    for (int n = 1; n <= 25; n++)
    {
        cout << n << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "* ";
            }
            cout << endl;
        }
        cout << endl
             << endl;
    }

    return 0;
}