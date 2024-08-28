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

    if (root == NULL)
        return;

    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        cout << f->val << " ";

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}

int main()
{

    Node *root = new Node(0);
    Node *b = new Node(1);
    Node *c = new Node(2);
    Node *d = new Node(3);
    Node *e = new Node(4);
    Node *f = new Node(5);
    Node *g = new Node(6);
    Node *h = new Node(7);
    Node *i = new Node(8);
    Node *j = new Node(9);
    Node *k = new Node(10);
    Node *l = new Node(11);
    Node *m = new Node(12);
    Node *n = new Node(13);
    Node *o = new Node(14);

    root->left = b;
    root->right = c;

    b->left = d;
    b->right = e;
    c->left = d;
    c->right = g;
    d->left = h;
    d->right = i;
    e->left = j;
    e->right = k;
    f->left = l;
    f->right = m;
    g->left = n;
    g->right = o;

    cout << "Level order:";
    level_order_traverse(root);

    return 0;
}