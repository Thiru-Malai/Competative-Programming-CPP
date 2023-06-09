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

void diagonalUtils(Node *root, int d, map<int, vector<int>> &diagonalPrint)
{
    if (root == NULL)
    {
        return;
    }
    diagonalPrint[d].push_back(root->data);

    diagonalUtils(root->left, d + 1, diagonalPrint);

    diagonalUtils(root->right, d, diagonalPrint);
}

void printDiagonal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    map<int, vector<int>> diagonalPrint;
    diagonalUtils(root, 0, diagonalPrint);

    cout << "DIAGONAL TRAVERSAL" << endl;
    for (auto &i : diagonalPrint)
    {
        for (auto j : i.second)
        {
            cout << j << " ";
        }
        cout<<endl;
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

    printDiagonal(root);
}

