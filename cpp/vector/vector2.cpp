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
    cout << "Original Vector elements:" << endl;
    for (int x : nums)
    {
        cout << x << " ";
    }
    cout << endl
         << "Vector elements that are smaller than its adjacent neighbors:" << endl;
    if (nums[0] < nums[1])
        cout << nums[0] << endl;
    for (int i = 1; i < n - 1; i++)
    {
        if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1])
            cout << nums[i] << endl;
    }
    if (nums[n] < nums[n - 1])
        cout << nums[0] << endl;

    sort(nums.begin(), nums.end());

    return 0;
}