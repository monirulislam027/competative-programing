#include <bits/stdc++.h>
using namespace std;

int checkOddness(string s, int l, int r)
{

    int arr[26] = {0};
    for (int i = l - 1; i < r; i++)
    {
        arr[s[i] - 'a']++;
    }
    int result = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > 0 && arr[i] % 2 != 0)
            result++;
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int len, query;
        string sen;
        cin >> len >> query >> sen;
        for (int j = 0; j < query; j++)
        {
            int l, r;
            cin >> l >> r;
            int result = checkOddness(sen, l, r);
            cout << result << endl;
        }
    }

    return 0;
}
