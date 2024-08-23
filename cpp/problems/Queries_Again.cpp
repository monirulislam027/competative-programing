#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int value)
    {
        this->val = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_normal(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
void print_reverse(Node *tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}
void insert_at_position(Node *head, int pos, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = temp;
}
void insert_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insert_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}
int size(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    int q, v, x;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> x >> v;
        if (x == 0)
        {
            insert_head(head, tail, v);
        }
        else if (x > size(head))
        {
            cout << "Invalid" << endl;
            continue;
        }
        else if (x == size(head))
        {
            insert_tail(head, tail, v);
        }
        else
        {
            insert_at_position(head, x, v);
        }
        if (head != NULL)
        {
            cout << "L -> ";
            print_normal(head);
        }
        if (head != NULL)
        {
            cout << "R -> ";
            print_reverse(tail);
        }
    }

    return 0;
}
