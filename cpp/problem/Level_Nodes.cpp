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

void getLevelValue(Node *root, int x)
{

    vector<int> xLevelNodes;
    queue<pair<Node *, int>> q;
    if (root != NULL)
        q.push({root, 0});

    while (!q.empty())
    {
        pair<Node *, int> front = q.front();
        q.pop();

        Node *f = front.first;
        int level = front.second;

        if (front.second == x)
        {
            xLevelNodes.push_back(f->val);
        }

        if (f->left)
            q.push({f->left, level + 1});
        if (f->right)
            q.push({f->right, level + 1});
    }

    if (xLevelNodes.empty())
    {
        cout << "Invalid";
        return;
    }
    for (int leaf : xLevelNodes)
    {
        cout << leaf << " ";
    }
}

int main()
{
    // Write your code here
    Node *root = create_tree();
    int x;
    cin >> x;
    getLevelValue(root, x);
    return 0;
}
