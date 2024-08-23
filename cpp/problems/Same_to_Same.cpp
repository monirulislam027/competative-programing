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

int linkedList_size(Node *head, int value)
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

int main()
{

    Node *head1 = NULL;
    Node *tail1 = NULL;
    int listSize1 = 0;
    while (true)
    {

        int value;
        cin >> value;
        if (value == -1)
            break;
        listSize1++;
        linkedList_insert(head1, tail1, value);
    }

    Node *head2 = NULL;
    Node *tail2 = NULL;
    int listSize2 = 0;
    while (true)
    {

        int value;
        cin >> value;
        if (value == -1)
            break;
        listSize2++;
        linkedList_insert(head2, tail2, value);
    }
    if (listSize1 != listSize2)
    {
        cout << "NO";
    }
    else
    {
        bool isSame = true;
        Node *temp = head1, *temp2 = head2;
        while (listSize1--)
        {
            if (temp->value != temp2->value)
            {
                isSame = false;
                break;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        isSame ? cout << "YES" : cout << "NO";
    }

    return 0;
}
