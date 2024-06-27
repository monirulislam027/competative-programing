#include <bits/stdc++.h>

using namespace std;

class Student
{
public:
    int id;
    string name;
    char section;
    int marks;
    Student()
    {
        cin >> this->id >> this->name >> this->section >> this->marks;
    }
};

void giveOutput(Student *first)
{
    cout << first->id << " " << first->name << " " << first->section << " " << first->marks << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {

        Student *first = new Student();
        Student *second = new Student();
        Student *third = new Student();
        if (first->marks > second->marks && first->marks > third->marks)
        {
            giveOutput(first);
        }
        else if (second->marks > third->marks && second->marks > first->marks)
        {
            giveOutput(second);
        }
        else if (third->marks > first->marks && third->marks > second->marks)
        {
            giveOutput(third);
        }
        else if (first->marks == second->marks)
        {
            (first->id < second->id) ? giveOutput(first) : giveOutput(second);
        }
        else if (first->marks == third->marks)
        {
            (first->id < third->id) ? giveOutput(first) : giveOutput(third);
        }
        else if (second->marks == third->marks)
        {
            (second->id < third->id) ? giveOutput(second) : giveOutput(third);
        }
    }

    return 0;
}
