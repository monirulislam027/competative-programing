#include <bits/stdc++.h>

using namespace std;

void print(list<int> nums)
{

    cout << "L -> ";
    auto it = nums.begin();
    while (it != nums.end())
    {
        cout << *it << " ";
        it = next(it);
    }
    cout << endl
         << "R -> ";
    if (nums.size() > 0)
    {

        it = prev(nums.end());
        while (it != nums.begin())
        {
            cout << *it << " ";
            it = prev(it);
        }
        cout << *it;
    }
    cout << endl;
}

int main()
{
    list<int> nums;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, v;
        cin >> x >> v;
        if (x == 0)
        {
            nums.push_front(v);
        }
        else if (x == 1)
        {
            nums.push_back(v);
        }
        else if (x == 2)
        {
            int size = nums.size();
            if (size == 0 || v >= size)
            {
                print(nums);
                continue;
            }
            else
            {
                nums.erase(next(nums.begin(), v));
            }
        }

        print(nums);
    }

    return 0;
}
