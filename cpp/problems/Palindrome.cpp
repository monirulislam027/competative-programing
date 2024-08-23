#include <bits/stdc++.h>

using namespace std;

int main()
{
    list<int> nums;

    while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
            break;
        nums.push_back(val);
    }

    auto i = nums.begin();
    auto j = prev(nums.end());
    bool flag = true;
    while (i != j && next(i) != j)
    {
        if (*i != *j)
        {
            flag = false;
            break;
        }
        i = next(i);
        j = prev(j);
    }
    if (*i != *j)
    {
        flag = false;
    }
    flag ? cout << "YES" : cout << "NO";

    return 0;
}
