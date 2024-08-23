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

void insert_at_tail(Node *&head, int val)
{

    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

int linkedList_size(Node *head)
{
    int i = 0;
    Node *current = head;
    while (current != NULL)
    {
        i++;
        current = current->next;
    }
    return i;
}

void print_linkedList(Node *head)
{
    cout << endl;
    Node *current = head;

    while (current != NULL)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl
         << endl;
}

int main()
{
    Node *head = NULL;
    while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
            break;
        insert_at_tail(head, val);
    }

    int size = linkedList_size(head);
    cout << size;

    return 0;
}