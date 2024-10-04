#include <bits/stdc++.h>

using namespace std;

class cmp
{
public:
    bool operator()(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
    {
        if (a.second.first == b.second.first)
            return a.second.second > b.second.second;
        return a.second.first < b.second.first;
    }
};

int main()
{
    // Write your code here
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);

        map<string, pair<int, int>> mp;

        stringstream ss(str);
        string word;
        int cnt = 0;
        while (ss >> word)
        {
            mp[word].first++;
            mp[word].second = cnt;
            cnt++;
        }

        stringstream ss2(str);
        string word2;
        string max;
        int maxCount = 0;
        while (ss2 >> word2)
        {
            int count = mp[word2].first;
            if (!mp.count(word2))
                continue;
            if (count > maxCount)
            {
                max = word2;
                maxCount = count;
            }
            else if (count == maxCount)
            {
                if (mp[word2].second < mp[max].second)
                {
                    max = word2;
                    maxCount = mp[word2].first;
                }
            }
        }

        cout << max << " " << maxCount << " " << endl;
    }

    return 0;
}
