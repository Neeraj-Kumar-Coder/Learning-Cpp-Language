#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack : public Node
{
private:
    Node *top;

public:
    Stack(void);
    int isEmpty(void);
    void push(int);
    int pop(void);
    int stackTop(void);
    int stackBottom(void);
};

Stack::Stack(void)
{
    top = NULL;
}

int Stack::isEmpty(void)
{
    return !top;
}

void Stack::push(int key)
{
    Node *element = new Node;
    element->data = key;
    element->next = top;
    top = element;
}

int Stack::pop(void)
{
    if (!isEmpty())
    {
        int key = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return key;
    }
    cout << "The stack is Empty!!!\n";
    return -1;
}

int Stack::stackTop(void)
{
    if (!isEmpty())
    {
        return top->data;
    }
    cout << "The stack is Empty!!!\n";
    return -1;
}

int Stack::stackBottom(void)
{
    if (!isEmpty())
    {
        Node *temp = top;
        while (temp->next)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    cout << "The stack is Empty!!!\n";
    return -1;
}

int main(void)
{
    Stack s;
    int choice, key;
    do
    {
        cout << "What do you want to perform:\n0. EXIT\n1. Push\n2. Pop\n3. Stack top\n4. Stack bottom\n==> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the number you want to push to the stack: ";
            cin >> key;
            s.push(key);
            break;
        case 2:
            cout << "The popped item is: " << s.pop() << '\n';
            break;
        case 3:
            cout << "The item in the stack top is: " << s.stackTop() << '\n';
            break;
        case 4:
            cout << "The item in the stack bottom is: " << s.stackBottom() << '\n';
            break;
        default:
            break;
        }
    } while (choice);

    return 0;
}