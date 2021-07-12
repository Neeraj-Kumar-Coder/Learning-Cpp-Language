#include <iostream>

using namespace std;

class Stack
{
    int maxSize;
    int top;
    int *arr;

public:
    Stack() {}
    Stack(int);
    int isFull(void);
    int isEmpty(void);
    int stackTop(void);
    int stackBottom(void);
    void push(int key);
    int pop(void);
};

Stack::Stack(int size)
{
    maxSize = size;
    arr = new int[size];
    top = -1;
}

int Stack::isFull(void)
{
    return top == maxSize - 1;
}

int Stack::isEmpty(void)
{
    return top == -1;
}

int Stack::stackTop(void)
{
    if (!this->isEmpty())
    {
        return arr[top];
    }
    return -1;
}

int Stack::stackBottom(void)
{
    if (!this->isEmpty())
    {
        return arr[0];
    }
    return -1;
}

void Stack::push(int key)
{
    if (!this->isFull())
    {
        arr[++top] = key;
    }
    cout << "Stack Overflow!!!\n";
}

int Stack::pop(void)
{
    if (!this->isEmpty())
    {
        return arr[top--];
    }
    cout << "Stack UnderFlow!!!\n";
    return -1;
}

int main(void)
{
    int size, choice, key;
    cout << "Enter the size of the stack you want to create: ";
    cin >> size;
    Stack s1(size);

    do
    {
        cout << "What do you want to perform:\n0. EXIT\n1. Push\n2. Pop\n3. Stack top\n4. Stack bottom\n==> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the number you want to push to the stack: ";
            cin >> key;
            s1.push(key);
            break;
        case 2:
            cout << "The popped item is: " << s1.pop() << '\n';
            break;
        case 3:
            cout << "The item in the stack top is: " << s1.stackTop() << '\n';
            break;
        case 4:
            cout << "The item in the stack bottom is: " << s1.stackBottom() << '\n';
            break;
        default:
            break;
        }
    } while (choice);

    return 0;
}