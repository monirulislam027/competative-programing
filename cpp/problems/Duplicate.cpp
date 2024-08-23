#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    bool flag = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            flag = true;
    }

    flag ? cout << "YES" : cout << "NO";
    cout << endl;

    return 0;
}
