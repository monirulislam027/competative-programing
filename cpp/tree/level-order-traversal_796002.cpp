#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<int> level_order_traverse(Node *root)
{
    vector<int> tr;
    if (root == NULL)
        return tr;

    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        tr.push_back(f->val);

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}

Node *create_tree()
{
    int val;
    cin >> val;
    if (val == -1)
        return NULL;
    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {

        Node *f = q.front();
        q.pop();
        Node *left, *right;
        int val1, val2;
        cin >> val1 >> val2;
        if (val1 != -1)
        {
            f->left = new Node(val1);
            q.push(f->left);
        }

        if (val2 != -1)
        {
            f->right = new Node(val2);
            q.push(f->right);
        }
    }
    return root;
}

void vector_print(vector<int> *data)
{
    for (int va : data)
    {
        cout << va << " ";
    }
    cout << endl;
}

int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        Node *root = create_tree();
        vector<int> data = level_order_traverse(root);
        vector_print(data);
        cout << endl;
    }
    return 0;
}