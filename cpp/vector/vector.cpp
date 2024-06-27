#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int x : nums)
    {
        cout << x << " ";
    }
    sort(nums.begin(), nums.end());
    int i = 0;
    int isOk = 1;
    while (i < nums.size() - 1)
    {
        if (nums[i] + 1 != nums[i + 1])
        {
            isOk = 0;
            break;
        }
        i++;
    }

    cout << endl
         << "Check consecutive numbers in the said vector! " << isOk;
    return 0;
}