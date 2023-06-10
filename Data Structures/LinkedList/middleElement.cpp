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

void reverse()
{
    Node *temp = head;
    Node *curr = NULL;
    Node *prev = NULL;

    while (temp != NULL)
    {
        curr = createNode(temp->data);
        curr->next = prev;
        prev = curr;
        temp = temp->next;
    }
    head = prev;
}

int findMiddleElement()
{
    Node *slow = head;
    Node *fast = head;
    Node *temp = head;
    while (temp)
    {
        if (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        temp = temp->next;
    }
    return slow->data;
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    print();
    reverse();
    print();

    cout << "MIDDLE ELEMENT " << findMiddleElement() << endl;
}