// LINKEDLIST
// Basic operations of Linked List:
// InsertAtEnd — Inserts a given element at the end of the linked list
// InsertAtHead — Inserts a given element at the start/head of the linked list
// Search — Returns the given element from a linked list
// Delete — Deletes a given element from the linked list
// DeleteAtHead — Deletes the first element of the linked list
// isEmpty — Returns true if the linked list is empty
// Print - Print the linked list
// Reverse() - Reverse a linked list


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

void insertAtHead(int num)
{
    if (isEmpty())
    {
        head = createNode(num);
        return;
    }

    Node *new_node = createNode(num);
    // Node* temp = head;
    new_node->next = head;
    head = new_node;
}

int searchNum(int num)
{
    if (isEmpty())
    {
        // cout<<"LIST EMPTY"<<endl;
        return 0;
    }
    Node *temp = head;
    while (temp && temp->data != num)
    {
        temp = temp->next;
    }
    if (temp && temp->data == num)
    {
        return 1;
    }
    return 0;
}

bool deleteNum(int num)
{
    if (isEmpty())
    {
        return false;
    }
    if (!searchNum(num))
    {
        return false;
    }

    Node *temp = head;
    while (temp->next)
    {
        if (temp->next->data == num)
        {
            temp->next = temp->next->next;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool deleteAtHead(int num)
{
    if (isEmpty())
    {
        return false;
    }
    if (head->data == num)
    {
        head = head->next;
        return true;
    }
    return false;
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

int main()
{
    int choice;
    int num;
    while (1)
    {
        cout << "LINKED LIST OPERATIONS\n1. Insert\n2. Insert At Head\n3. Search\n4. Delete\n5. Delete At Head\n6. isEmpty\n7. Print\n8. Reverse" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cin >> num;
            insert(num);
        }
        else if (choice == 2)
        {
            cin >> num;
            insertAtHead(num);
        }
        else if (choice == 3)
        {
            cin >> num;
            cout << searchNum(num) << endl;
        }
        else if (choice == 4)
        {
            cin >> num;
            cout << ((deleteNum(num) == true) ? "Deleted" : "Not Deleted") << endl;
        }
        else if (choice == 5)
        {
            cin >> num;
            cout << ((deleteAtHead(num) == true) ? "Deleted Head" : "Not Deleted") << endl;
        }
        else if (choice == 6)
        {
            cout << isEmpty() << endl;
        }
        else if (choice == 7)
        {
            print();
        }
        else
        {
            break;
        }
    }
}