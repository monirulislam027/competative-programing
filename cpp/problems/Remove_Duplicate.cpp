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

void linkedList_insert_head(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    if (tail == NULL)
    {
        tail = newNode;
    }
}
void linkedList_insert_tail(Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (tail == NULL)
    {
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void print_linkedList(Node *node)
{
    Node *temp = node;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}

bool find_value(Node *head, int value)
{
    bool isFound = false;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->value == value)
        {
            isFound = true;
            break;
        }
        temp = temp->next;
    }

    return isFound;
}

int main()
{

    Node *head = NULL, *tail = NULL;

    while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
            break;
        bool isFound = find_value(head, val);

        if (isFound == 1)
            continue;

        if (head == NULL)
        {
            linkedList_insert_head(head, tail, val);
        }
        else
        {
            linkedList_insert_tail(tail, val);
        }
    }

    print_linkedList(head);

    return 0;
}
