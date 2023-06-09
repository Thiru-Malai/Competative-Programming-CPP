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

void printCurrentLevel(Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    else if (level == 1)
    {
        cout << root->data << " ";
    }
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

int heightOfBST(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = heightOfBST(root->left);
    int rightHeight = heightOfBST(root->right);
    return max(leftHeight, rightHeight) + 1;
}

void printLevelOrder(Node *root)
{
    int h = heightOfBST(root);
    int i;
    for (i = 1; i <= h; i++)
    {
        printCurrentLevel(root, i);
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

    inOrder(root);
    cout << endl;

    printLevelOrder(root);
}
