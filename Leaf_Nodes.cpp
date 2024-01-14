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

void labelOrder(Node *root)
{
    vector<int> v;
    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (!node->left && !node->right)
        {
            v.push_back(node->val);
        }
        if (node->left)
        {
            q.push(node->left);
        }
        if (node->right)
        {
            q.push(node->right);
        }
    }

    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

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

int main()
{
    Node *root = input_tree();
    labelOrder(root);
    return 0;
}
