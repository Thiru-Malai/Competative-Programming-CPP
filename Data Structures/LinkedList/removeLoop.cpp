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

Node *removeLoop()
{
    Node *slow = head;
    Node *fast = head;

    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (fast->next == NULL)
    {
        return NULL;
    }
    slow = head;
    if (slow == fast)
    {
        while (fast->next != slow)
        {
            fast = fast->next;
        }
    }
    else
    {
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return fast;
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    head->next->next->next->next->next = head;

    // removeLoop();
    Node *lastNode = removeLoop();
    lastNode->next = NULL;

    print();
}