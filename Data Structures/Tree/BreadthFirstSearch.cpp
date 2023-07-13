#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};



Node* insert(Node* node, int data){
    if(node == NULL){
        Node* newnode = new Node(data);
        return newnode;
    }
    if(node->data > data){
        node->left = insert(node->left, data);
    }
    else{
        node->right = insert(node->right, data);
    }
    return node;
}

void inOrder(Node* root){
    if(root){
        cout<<root->data<<" ";
        inOrder(root->left);
        inOrder(root->right);
    }
}

void breadthFirstSearch(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* top = q.front();
        if(top->left != NULL){
            q.push(top->left);
        }
        if(top->right != NULL){
            q.push(top->right);
        }
        q.pop();
        cout<<top->data<<" ";
    }
}

int main(){
    Node* root = new Node(5);
    insert(root, 4);
    insert(root, 2);
    insert(root, 3);
    insert(root, 6);
    insert(root, 7);
    insert(root, 8);

    cout<<"InOrder Traversal"<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"Breadth First Search"<<endl;
    breadthFirstSearch(root);

}