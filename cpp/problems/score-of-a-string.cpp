#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string defangIPaddr(string address)
    {
        string result = address;
        while (result.find(".") != -1)
        {

            result.replace(result.find('.'), 1, "#");
        }
        while (result.find("#") != -1)
        {

            result.replace(result.find('#'), 1, "[.]");
        }
        return result;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    cout << sol.defangIPaddr(s);
    return 0;
}