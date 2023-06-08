#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
};

Node *createNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *insertNode(Node *node, int data)
{
    if (node == NULL)
    {
        return createNode(data);
    }
    if (node->data > data)
    {
        node->left = insertNode(node->left, data);
    }
    else
    {
        node->right = insertNode(node->right, data);
    }
    return node;
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

void printInOrder(Node *root)
{
    if (root)
    {
        printInOrder(root->left);
        cout << root->data << " ";
        printInOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 40);
    insertNode(root, 30);
    insertNode(root, 60);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 10);
    insertNode(root, 80);

    printInOrder(root);
    cout << endl;

    cout << "Height Of BST " << heightOfBST(root) << endl;
}
