// QUEUE
// Basic operations of Queue
// Enqueue() — Inserts an element to the end of the queue
// Dequeue() — Removes an element from the start of the queue
// isEmpty() — Returns true if the queue is empty
// Top() — Returns the first element of the queue

#include <bits/stdc++.h>
#define N 5
using namespace std;

int queue1[N];
int front = -1;
int rear = -1;

bool isFull()
{
    if (front == 0 && rear == N - 1)
    {
        return true;
    }
    return false;
}

bool isEmpty()
{
    if (front == -1)
    {
        return true;
    }
    return false;
}

void enqueue(int num)
{
    if (isFull())
    {
        cout << "OVERFLOW" << endl;
        return;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
    }
    queue1[++rear] = num;
}

int dequeue()
{
    int element;
    if (isEmpty())
    {
        cout << "UNDERFLOW" << endl;
        return -1;
    }
    else
    {
        element = queue1[front];
        if (front >= rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
    return element;
}

int top()
{
    if (isEmpty())
    {
        cout << "Empty" << endl;
        return -1;
    }
    return queue1[front];
}

int main()
{
    int choice;
    int num;
    while (1)
    {
        cout << "QUEUE OPERATIONS\n1. Enqueue\n2. Dequeue\n3. isEmpty\n4. Top" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> num;
            enqueue(num);
            break;
        case 2:
            cout << "Deleted Element " << dequeue() << endl;
            break;
        case 3:
            cout << (isEmpty() == true ? "Empty " : "Not Empty") << endl;
            break;
        case 4:
            cout << top() << endl;
            break;
        default:
            break;
        }
    }
}