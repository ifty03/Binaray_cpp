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

Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
    {
        root = NULL;
    }
    else
    {
        root = new Node(val);
    }

    queue<Node *> q;
    if (root)
    {
        q.push(root);
    }
    // manually push first value in queue

    while (!q.empty())
    {
        // first value ber kore ana
        Node *p = q.front();
        q.pop();

        // your work
        int l, r;
        cin >> l >> r;

        Node *left;
        Node *right;

        if (l == -1)
        {
            left = NULL;
        }
        else
        {
            left = new Node(l);
        }

        if (r == -1)
        {
            right = NULL;
        }
        else
        {
            right = new Node(r);
        }

        p->left = left;
        p->right = right;

        // push children
        if (p->left)
        {
            q.push(p->left);
        }
        if (p->right)
        {
            q.push(p->right);
        }
    }

    return root;
}

void print_left(Node *root)
{
    if (root == NULL)
        return;
    if (root->left)
    {
        print_left(root->left);
        cout << root->val << " ";
    }
    else if (root->right)
    {
        print_left(root->right);
        cout << root->val << " ";
    }
    else
    {
        cout << root->val << " ";
    }
}
void print_right(Node *root)
{
    if (root == NULL)
        return;
    if (root->right)
    {
        cout << root->val << " ";
        print_right(root->right);
    }
    else if (root->left)
    {
        cout << root->val << " ";
        print_right(root->left);
    }
    else
    {
        cout << root->val << " ";
    }
}

int main()
{
    Node *root = input_tree();
    if (root)
    {

        print_left(root->left);
        cout << root->val << " ";
        print_right(root->right);
    }
    return 0;
}
