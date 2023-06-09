#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    int hd;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};

Node *create_node(int data)
{
    Node *newnode = new Node(data);
    return newnode;
}

Node *insert(Node *node, int data)
{
    if (node == NULL)
    {
        return create_node(data);
    }

    if (node->data > data)
    {
        node->left = insert(node->left, data);
    }
    else
    {
        node->right = insert(node->right, data);
    }
    return node;
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void printTopView(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    int hd = 0;
    queue<Node *> q;
    map<int, int> m;
    root->hd = hd;
    q.push(root);

    while (q.size())
    {
        hd = root->hd;
        if (m.count(hd) == 0)
        {
            m[hd] = root->data;
        }
        if (root->left)
        {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if (root->right)
        {
            root->right->hd = hd + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }

    for (auto &i : m)
    {
        cout << i.second << " ";
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);
    insert(root, 13);
    insert(root, 4);
    insert(root, 7);

    inOrder(root);
    cout << endl;

    printTopView(root);
}
