#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    long long int value;
    Node *next;
    Node(long long int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

void linkedList_insert_head(Node *&head, Node *&tail, long long int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    if (tail == NULL)
    {
        tail = newNode;
    }
}
void linkedList_insert_tail(Node *&tail, long long int value)
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
int linkedList_size(Node *head)
{
    int size = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }

    return size;
}

void linkedList_delete(Node *&head, Node *&tail, int index, int size)
{
    if (index > size - 1)
    {
        return;
    }
    if (index == 0)
    {
        Node *deleteNode = head;
        head = head->next;
        delete deleteNode;
        return;
    }
    Node *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    if (temp->next->next == NULL)
    {
        tail = temp;
    }
    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
}

int main()
{

    Node *head = NULL, *tail = NULL;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {

        int x;
        long long int v;
        cin >> x >> v;
        if (x == 0)
        {
            linkedList_insert_head(head, tail, v);
        }
        else if (x == 1)
        {
            if (head == NULL)
            {
                linkedList_insert_head(head, tail, v);
            }
            else
            {
                linkedList_insert_tail(tail, v);
            }
        }
        else if (x == 2)
        {
            linkedList_delete(head, tail, v, linkedList_size(head));
        }

        print_linkedList(head);
        cout << endl;
    }

    return 0;
}
