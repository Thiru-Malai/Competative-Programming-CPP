// STACK
// Basic operations of stack:
// Push — Inserts an element at the top
// Pop — Returns the top element after removing from the stack
// Top — Returns the top element without removing from the stack
// isEmpty — Returns true if the stack is empty
// isFull - Returns true if the stack is full


#include <iostream>
#define N 5
using namespace std;

int stack1[N];
int top = -1;

void push(int num)
{
    if (isFull())
    {
        cout << "OVERFLOW" << endl;
        return;
    }
    stack1[++top] = num;
}

int pop()
{
    if (isEmpty())
    {
        cout << "UNDERFLOW";
        return -1;
    }
    return stack1[top--];
}

int topElement()
{
    if (isEmpty())
    {
        cout << "UNDERFLOW" << endl;
        return -1;
    }
    return stack1[top];
}

bool isFull()
{
    if (top == N - 1)
    {
        return true;
    }
    return false;
}

bool isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

int main()
{
    int choice;
    int num;
    while (1)
    {
        cout << "STACK OPERATIONS\n"
             << "1. INSERT\n"
             << "2. DELETE\n"
             << "3. TOP\n"
             << "4. ISEMPTY\n";
        cin >> choice;
        if (choice == 1)
        {
            cin >> num;
            push(num);
        }
        else if (choice == 2)
        {
            cout << pop() << endl;
        }
        else if (choice == 3)
        {

            cout << topElement() << endl;
        }
        else if (choice == 4)
        {
            cout << isEmpty() << endl;
        }
        else
        {
            break;
        }
    }
}