#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n;
    cin >> n;
    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long int arr2[n];
    arr2[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        arr2[i] = arr2[i - 1] + arr[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        cout << arr2[i] << " ";
    }

    return 0;
}
