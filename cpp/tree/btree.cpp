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

void pre_order(Node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    pre_order(root->left);
    pre_order(root->right);
}
void in_order(Node *root)
{
    if (root == NULL)
        return;
    pre_order(root->left);
    cout << root->val << " ";
    pre_order(root->right);
}
void post_order(Node *root)
{
    if (root == NULL)
        return;
    pre_order(root->left);
    pre_order(root->right);
    cout << root->val << " ";
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

    cout << "Pre order:";
    pre_order(root);
    cout << endl;
    cout << "In order:";
    in_order(root);
    cout << endl;
    cout << "Post order:";
    post_order(root);
    cout << endl;

    return 0;
}