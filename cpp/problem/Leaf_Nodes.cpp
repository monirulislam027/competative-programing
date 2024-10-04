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

void level_order_traverse(Node *root)
{
    vector<int> leafNodes;
    queue<Node *> q;
    if (root != NULL)
        q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        if (f->left == NULL && f->right == NULL)
            leafNodes.push_back(f->val);

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }

    sort(leafNodes.begin(), leafNodes.end(), greater<int>());
    for (int leaf : leafNodes)
    {
        cout << leaf << " ";
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
    level_order_traverse(root);
    return 0;
}
