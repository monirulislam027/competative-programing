#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

void linkedList_insert(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

int main()
{
    // Write your code here
    Node *head = NULL;
    Node *tail = NULL;
    while (true)
    {
        int value;
        cin >> value;
        if (value == -1)
            break;
        linkedList_insert(head, tail, value);
    }
    int min = INT_MAX;
    int max = INT_MIN;

    Node *temp = head;
    while (temp != NULL)
    {

        if (temp->value < min)
            min = temp->value;
        if (temp->value > max)
            max = temp->value;

        temp = temp->next;
    }
    cout << max - min;
    return 0;
}
