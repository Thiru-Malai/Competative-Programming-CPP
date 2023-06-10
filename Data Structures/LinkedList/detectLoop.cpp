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

bool detectLoop(){
    if(head == NULL){
        return 0;
    }

    unordered_set<Node*> m;
    while(head){
        if(m.find(head) != m.end())
            return 1;
        m.insert(head);

        head = head->next;
    }
    return 0;
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    head->next->next->next->next->next = head;

    // print();         // Do not print since cycle exists - leads to infinite loop

    cout << detectLoop();

}