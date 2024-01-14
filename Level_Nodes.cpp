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

int maxHeight(Node *root)
{
    if (root == NULL)
        return 0;
    int l = maxHeight(root->left);
    int r = maxHeight(root->right);
    return max(l, r) + 1;
}

void printLevel(Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    int c = 0;
   queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node *p = q.front();
            q.pop();

            if (c == level)
            {
                cout << p->val << " ";
            }

            if (p->left != NULL)
            {
                q.push(p->left);
            }

            if (p->right != NULL)
            {
                q.push(p->right);
            }
        }

        c++;

        if (c > level)
        {
            break;
        }
    }
}
int main()
{
    Node *root = input_tree();
    int label;
    cin >> label;

    int m = maxHeight(root);
    if ((label < 0) || (label > m-1))
    {
        cout << "Invalid" << endl;
    }
    else
    {

        printLevel(root, label);
    }

    return 0;
}
