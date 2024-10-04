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

bool isPerfectTree(Node *root)
{
    if (root == NULL)
        return false;
    if (root->left == NULL && root->right == NULL)
        return true;
    bool l = isPerfectTree(root->left);
    bool r = isPerfectTree(root->right);
    return l && r;
}

int main()
{
    // Write your code here
    Node *root = create_tree();
    bool result = isPerfectTree(root);
    result ? cout << "YES" : cout << "NO";
    return 0;
}
