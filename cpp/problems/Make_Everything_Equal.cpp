#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        sort(arr, arr + n);
        int arr2[1001] = {0};
        for (int k = 0; k < n; k++)
        {
            arr2[arr[k]]++;
        }

        int count = 0;

        for (int j = 0; j < 1001; j++)
        {
            if (arr2[j] > 0 && arr2[j] > count)
                count = arr2[j];
        }
        k - (n - count) >= 0 ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}