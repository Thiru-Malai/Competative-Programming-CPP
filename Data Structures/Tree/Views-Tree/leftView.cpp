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


void leftViewUtil(Node* root, int level, int *maxLevel){
    if(root == NULL){
        return;
    }
    if(*maxLevel < level){
        cout<<root->data<<" ";
        *maxLevel = level;
    }
    leftViewUtil(root->left, level + 1, maxLevel);
    leftViewUtil(root->right, level + 1, maxLevel);
}

void printLeftView(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    int maxLevel = 0;
    leftViewUtil(root, 1, &maxLevel);
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

    printLeftView(root);
}