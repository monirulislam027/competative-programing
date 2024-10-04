#include <bits/stdc++.h>

using namespace std;

class Student
{
public:
    long long i;
    string s;

    Student(string s, long long i)
    {
        this->s = s;
        this->i = i;
    }
};

class cmp
{
public:
    bool operator()(Student a, Student b)
    {
        if (a.s == b.s)
            return a.i < b.i;
        return a.s > b.s;
        // if (a.s > b.s)
        //     return true;
        // else if (a.s < b.s)
        //     return false;
        // else
        // {
        //     if (a.i < b.i)
        //         return true;
        //     else
        //         return false;
        // }
    }
};

int main()
{
    // Write your code here
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<Student, vector<Student>, cmp> pq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        long long num;
        cin >> s >> num;
        Student st(s, num);
        pq.push(st);
    }

    while (!pq.empty())
    {
        Student st = pq.top();
        cout << st.s << " " << st.i << "\n";
        pq.pop();
    }

    return 0;
}
