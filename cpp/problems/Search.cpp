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

int find_index(Node *head, int value)
{
    int index = -1;
    bool isFound = false;

    Node *temp = head;
    while (temp != NULL)
    {
        index++;
        if (temp->value == value)
        {
            isFound = true;
            break;
        }
        temp = temp->next;
    }

    return isFound ? index : -1;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
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
        int value;
        cin >> value;
        cout << find_index(head, value) << endl;
    }
    return 0;
}
