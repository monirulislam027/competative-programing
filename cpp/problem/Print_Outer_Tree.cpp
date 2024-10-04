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

void traverse(Node *root, int sl)
{
    if (root == NULL)
        return;
    if (sl == 0)
    {
        if (root->left)
            traverse(root->left, sl);
        else if (root->right)
            traverse(root->right, sl);

        cout << root->val << " ";
        return;
    }
    if (sl == 1)
    {
        cout << root->val << " ";
        if (root->right)
            traverse(root->right, sl);
        else if (root->left)
            traverse(root->left, sl);

        return;
    }
}

int main()
{
    // Write your code here
    Node *root = create_tree();
    traverse(root->left, 0);
    cout << root->val << " ";
    traverse(root->right, 1);
    return 0;
}
