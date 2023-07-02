#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(){
            this->data = 0;
            this->next = NULL;
            this->prev = NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};


void insert(Node* *head, int data){
    if(*head == NULL){
        *head = new Node(data);
        return;
    }
    Node* temp = *head;
    while(temp->next){
        temp = temp->next;
    }
    Node* new_node = new Node(data);
    temp->next = new_node;
    new_node->prev = temp;
}

Node* removeDuplicates(Node* head){
    Node* temp = head;
    while(temp && temp->next){
        if(temp->data == temp->next->data){
            temp->next = temp->next->next;
            if(temp->next){
                temp->next->prev = temp;
            }
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 3);
    insert(&head, 4);
    print(head);

    Node* resHead = removeDuplicates(head);
    print(resHead);
}