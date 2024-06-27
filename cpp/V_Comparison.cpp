#include <bits/stdc++.h>
using namespace std;
int main()
{

    int a, b;
    char sign;
    cin >> a >> sign >> b;
    if (sign == '>' && a > b)
    {
        cout << "Right" << endl;
    }
    else if (sign == '<' && a < b)
    {
        cout << "Right" << endl;
    }
    else if (sign == '=' && a == b)
    {
        cout << "Right" << endl;
    }
    else
    {
        cout << "Wrong" << endl;
    }

    return 0;
}