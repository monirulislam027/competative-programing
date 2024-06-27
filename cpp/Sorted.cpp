#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        bool flag = true;
        for (int k = 0; k < n - 1; k++)
        {
            if (arr[k] > arr[k + 1])
                flag = false;
        }

        flag ? cout << "YES" : cout << "NO";
        cout << endl;
    }

    return 0;
}
