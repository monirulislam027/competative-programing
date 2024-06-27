#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<int> v = {1, 2, 3, 4, 5};
    v.erase(v.begin() + 2, v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << i << " " << v[i] << endl;
    }
    return 0;
}
