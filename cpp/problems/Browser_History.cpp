#include <bits/stdc++.h>

using namespace std;

int main()
{
    list<string> history;
    while (true)
    {
        string val;
        cin >> val;
        if (val == "end")
            break;
        history.push_back(val);
    }

    int n;
    cin >> n;
    auto current = history.begin();
    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "visit")
        {
            string value;
            cin >> value;

            auto temp = history.begin();
            bool isFound = false;
            while (temp != history.end())
            {
                if (*temp == value)
                {
                    current = temp;
                    isFound = true;
                    cout << *current << endl;
                    break;
                }
                temp = next(temp);
            }
            if (isFound == false)
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "prev")
        {
            if (current != history.begin())
            {

                current = prev(current);
                cout << *current << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else
        {
            if (next(current) != history.end())
            {
                current = next(current);
                cout << *current << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}
