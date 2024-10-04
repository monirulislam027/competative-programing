#include <bits/stdc++.h>

using namespace std;

class Student
{
public:
    string name;
    int roll;
    int marks;

    Student(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

class cmp
{
public:
    bool operator()(Student a, Student b)
    {
        if (a.marks < b.marks)
            return true;
        else if (a.marks > b.marks)
            return false;
        else
        {
            if (a.roll > b.roll)
                return true;
            else
                return false;
        }
    }
};

void printStudent(Student st)
{
    cout << st.name << " " << st.roll << " " << st.marks << "\n";
}

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
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        Student st(name, roll, marks);
        pq.push(st);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 0)
        {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            Student st(name, roll, marks);
            pq.push(st);
            if (!pq.empty())
                printStudent(pq.top());
            else
                cout << "Empty\n";
        }
        else if (cmd == 1)
        {
            if (!pq.empty())
                printStudent(pq.top());
            else
                cout << "Empty\n";
        }
        else if (cmd == 2)
        {
            if (!pq.empty())
                pq.pop();

            if (!pq.empty())
                printStudent(pq.top());
            else
                cout << "Empty\n";
        }
    }

    return 0;
}
