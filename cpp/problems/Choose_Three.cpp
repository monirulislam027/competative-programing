#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, s;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> s;
        int arr[n];
        for (int m = 0; m < n; m++)
        {
            cin >> arr[m];
        }
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {

                    if (arr[j] + arr[k] + arr[l] == s)
                    {
                        flag = 1;
                    }
                }
            }
        }
        if (flag == 1)
        {

            cout << "YES " << endl;
        }
        else
        {

            cout << "NO" << endl;
        }
        flag = 0;
    }

    return 0;
}
