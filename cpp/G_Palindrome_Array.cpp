#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int isPalindrome = 1;
    int i = 0, j = n - 1;
    // bool i = i > j;
    while (1)
    {
        if (i >= j)
            break;
        if (arr[i] != arr[j])
        {
            isPalindrome = 0;
            break;
        }
        i++;
        j--;
    }

    isPalindrome == 1 ? cout << "YES" : cout << "NO";

    return 0;
}