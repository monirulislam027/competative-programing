#include <bits/stdc++.h>

using namespace std;

class Student
{
public:
    string nm;
    int cls, id;
    char s;
};

int main()
{
    int n;
    cin >> n;

    Student st[n];
    for (int i = 0; i < n; i++)
    {
        cin >> st[i].nm >> st[i].cls >> st[i].s >> st[i].id;
    }

    int i = 0, j = n - 1;
    while (i <= j)
    {
        swap(st[i].s, st[j].s);
        i++;
        j--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << st[i].nm << " " << st[i].cls << " " << st[i].s << " " << st[i].id << endl;
    }

    return 0;
}
