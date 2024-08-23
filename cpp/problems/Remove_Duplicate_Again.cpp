#include <bits/stdc++.h>

using namespace std;

bool isFound(list<int> nums, int val)
{
}

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
    nums.sort();
    nums.unique();

    for (auto i = nums.begin(); i != nums.end(); i++)
    {
        cout << *i << " ";
    }

    return 0;
}
