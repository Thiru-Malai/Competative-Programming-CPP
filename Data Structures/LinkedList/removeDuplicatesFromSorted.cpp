
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->next = NULL;
        this->data = data;
    }
};

Node *head = NULL;

bool isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}

Node *createNode(int data)
{
    Node *new_node = new Node(data);
    return new_node;
}

void insert(int num)
{
    Node *temp = head;
    if (isEmpty())
    {
        head = createNode(num);
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = createNode(num);
}

void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void removeDuplicates(){
    if(head == NULL){
        return;
    }
    
    Node* temp = head;
    Node* index = NULL;

    while(temp){
        index = temp->next;
        while(index){
            if(temp->data == index->data){
                temp->next = index->next;
                free(index);
                index = temp->next;
            }
            else{
                index = index->next;
            }
        }
        temp = temp->next;
    }
}

int main()
{
    insert(1);
    insert(2);
    insert(2);
    insert(3);
    insert(5);

    print();
    removeDuplicates();
    print();
}
