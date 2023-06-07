// BINARY SEARCH TREE TO DOUBLY LINKED LIST


#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
};

class DLL
{
public:
    int data;
    DLL *right;
    DLL *left;
};

DLL *rootdll = NULL;


Node *newnode(int data)
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
        return newnode(data);
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

void printInOrder(Node *root)
{
    if (root)
    {
        printInOrder(root->left);
        cout << root->data << " ";
        printInOrder(root->right);
    }
}

DLL *createDLL(int data)
{
    DLL *new_node = new DLL;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insertDLL(int data)
{
    if (rootdll == NULL)
    {
        rootdll = createDLL(data);
    }

    DLL* temp = rootdll;
    while(temp->right){
        temp = temp->right;
    }

    DLL* new_node = new DLL;
    new_node->data = data;
    new_node->right = NULL;
    new_node->left = temp;
    temp->right = new_node;
    temp = temp->right;
}

void getNodeData(Node *root)
{
    if (root)
    {
        getNodeData(root->left);
        insertDLL(root->data);
        getNodeData(root->right);
    }
}


void printDLL(){
    DLL* temp = rootdll;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
}

int main()
{
    int arr[] = {5, 3, 2, 4, 1};
    Node *root = NULL;
    root = insertNode(root, arr[0]);
    for (int i = 1; i < 5; i++)
    {
        insertNode(root, arr[i]);
    }

    printInOrder(root);

    getNodeData(root);

    printDLL();
}
