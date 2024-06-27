#include <bits/stdc++.h>
using namespace std;
int main()
{

    int A, B, C;
    char S, Q;
    cin >> A >> S >> B >> Q >> C;
    int val;
    if (S == '+')
    {
        val = A + B;
    }
    else if (S == '-')
    {
        val = A - B;
    }
    else if (S == '*')
    {
        val = A * B;
    }
    (val == C) ? cout << "Yes" : cout << val << endl;
    return 0;
}