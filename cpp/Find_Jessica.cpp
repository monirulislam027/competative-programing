#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, word;
    int isFound = 0;
    getline(cin, s);
    stringstream ss;
    ss << s;

    while (ss >> word)
    {

        if (word == "Jessica")
        {
            isFound = 1;
        }
    }

    (isFound == 1) ? cout << "YES" : cout << "NO";

    return 0;
}
