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
    
    unordered_set<int> seen;

    Node* temp = head;
    Node* prev = NULL;

    while(temp){
        if(seen.find(temp->data) != seen.end()){
            prev->next = temp->next;
            delete(temp);
        }
        else{
            prev = temp;
            seen.insert(temp->data);
        }
        temp = prev->next;
    }
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(2);
    insert(5);

    print();
    removeDuplicates();
    print();
}
