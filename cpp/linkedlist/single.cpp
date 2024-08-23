#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_head(Node *&head, int val)
{

    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    cout << endl
         << "Inserted at head" << endl
         << endl;
}

void insert_at_tail(Node *head, int val)
{

    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    Node *newNode = new Node(val);
    current->next = newNode;
    cout << endl
         << "Inserted at tail" << endl
         << endl;
}

void insert_at_position(Node *head, int position, int value)
{

    Node *current = head;
    int i = 1;
    while (i < position)
    {
        current - current->next;
        i++;
    }
    Node *newNode = new Node(value);
    newNode->next = current->next;
    current->next = newNode;
    cout << endl
         << "Inserted at position " << position << endl
         << endl;
}

void delete_head(Node *&head)
{
    if (head == NULL)
        return;

    Node *tempHead = head;
    head = tempHead->next;
    delete tempHead;
    cout << endl
         << "Head deleted!" << endl
         << endl;
}

void delete_tail(Node *head)
{

    Node *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    Node *tailNode = current->next;
    current->next = NULL;
    delete tailNode;

    cout << endl
         << "Tail deleted!" << endl
         << endl;
}

void delete_at_position(Node *head, int position)
{

    Node *temp = head;

    int i = 1;
    while (i < position)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            cout << endl
                 << "Invalid index" << endl
                 << endl;
            return;
        }
        i++;
    }

    Node *deleteNode = temp;
    temp->next = temp->next->next;
    delete deleteNode;

    cout << endl
         << "Deleted at index " << position << endl
         << endl;
}

void print_linkedList(Node *head)
{
    cout << endl;
    Node *current = head;

    while (current != NULL)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl
         << endl;
}
void print_linkedListRecursion(Node *node)
{
    if (node == NULL)
        return;
    print_linkedListRecursion(node->next);
    cout << node->val << " ";
}

int main()
{

    Node *head = NULL;
    int arr[5] = {1, 2, 3, 4, 5};
    insert_at_head(head, arr[0]);
    for (int i = 1; i < 5; i++)
    {
        insert_at_tail(head, arr[i]);
    }
    print_linkedListRecursion(head);
    while (false)
    {
        cout << "0: Terminate" << endl;
        cout << "1: Insert at head" << endl;
        cout << "2: Insert at tail" << endl;
        cout << "3: Insert at any position" << endl;
        cout << "4: Delete head" << endl;
        cout << "5: Delete tail" << endl;
        cout << "6: Delete at any index" << endl;
        cout << "7: Print List" << endl;
        cout << endl
             << "Enter an option: ";

        int op;
        cin >> op;
        cout << endl;
        if (op == 0)
        {
            break;
        }
        if (op == 1)
        {
            cout << "Enter a value: ";
            int value;
            cin >> value;
            insert_at_head(head, value);
        }
        else if (op == 2)
        {
            cout << "Enter a value: ";
            int value;
            cin >> value;
            if (head == NULL)
            {
                insert_at_head(head, value);
            }
            else
            {
                insert_at_tail(head, value);
            }
        }
        else if (op == 3)
        {
            int value, position;
            cout << "Enter a value: ";
            cin >> value;
            cout << "Enter a position: ";
            cin >> position;
            if (position == 0)
            {
                insert_at_head(head, value);
            }
            else
            {
                insert_at_position(head, position, value);
            }
        }
        else if (op == 4)
        {
            delete_head(head);
        }
        else if (op == 5)
        {
            if (head == NULL || head->next == NULL)
            {
                delete_head(head);
            }
            else
            {
                delete_tail(head);
            }
        }
        else if (op == 6)
        {
            int position;
            cout << "Enter a position: ";
            cin >> position;
            if (position == 0)
            {
                delete_head(head);
            }
            else
            {
                delete_at_position(head, position);
            }
        }
        else if (op == 7)
        {
            print_linkedList(head);
        }
    }

    return 0;
}