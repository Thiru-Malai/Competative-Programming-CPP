#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
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

void printAncestors(Node *root, Node *node)
{
    if (root == NULL)
    {
        return;
    }
    if (node->data < root->data)
    {
        printAncestors(root->left, node);
        cout << root->data << " ";
    }
    else if(node->data > root->data)
    {
        printAncestors(root->right, node);
        cout << root->data << " ";
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 10);

    Node *node = root->left->right;

    cout << "INORDER TRAVERSAL " << endl;
    inOrder(root);
    cout << endl;
    printAncestors(root, node);
}