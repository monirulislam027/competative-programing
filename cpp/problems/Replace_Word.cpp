#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {

        string sen;
        getline(cin, sen);

        string word1, word2;
        stringstream ss;
        ss << sen;

        ss >> word1;
        ss >> word2;
        while (word1.find(word2) != -1)
        {
            word1.replace(word1.find(word2), word2.length(), "#");
        }

        cout << word1 << endl;
    }

    return 0;
}
