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

int getSum(Node *root)
{
    queue<Node *> q;
    int sum = 0;

    if (root != NULL)
        q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        if (f->right != NULL || f->left != NULL)
        {
            sum += f->val;
        }
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
    return sum;
}

int getSum2(Node *root)
{

    if (root == NULL)
        return 0;
    int left = getSum2(root->left);
    int right = getSum2(root->right);

    if (root->left != NULL || root->right != NULL)
        return left + right + root->val;
    return 0;
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

int main()
{
    // Write your code here
    Node *root = create_tree();
    int sum = getSum2(root);
    cout << sum << endl;
    return 0;
}
