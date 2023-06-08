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

Node *minValueNode(Node *node)
{
    Node *curr = node;
    while (curr && curr->left)
    {
        curr = curr->left;
    }
    return curr;
}

Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        else if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
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

void preOrder(Node *root)
{
    if (root)
    {
        preOrder(root->left);
        cout << root->data << " ";
        preOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if (root)
    {
        postOrder(root->left);
        cout << root->data << " ";
        postOrder(root->right);
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

    cout << "INORDER TRAVERSAL " << endl;
    inOrder(root);

    root = deleteNode(root, 20);
    cout << endl << "INORDER TRAVERSAL AFTER DELETION " << endl;
    inOrder(root);

    cout << endl << "PREORDER TRAVERSAL " << endl;
    preOrder(root);

    cout << endl << "POSTORDER TRAVERSAL " << endl;
    postOrder(root);
}