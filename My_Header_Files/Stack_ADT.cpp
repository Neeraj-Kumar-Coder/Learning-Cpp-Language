#ifndef STACK_ADT
#define STACK_ADT
template <class type>
class NodeforStack
{
public:
    type data;
    NodeforStack<type> *next;
};

template <class type>
class Stack
{
private:
    NodeforStack<type> *top;

public:
    Stack(void) { top = NULL; }
    int isEmpty(void)
    {
        return !top;
    }
    void push(type key)
    {
        if (!top)
        {
            top = new NodeforStack<type>;
            top->data = key;
            top->next = NULL;
            return;
        }
        NodeforStack<type> *newNode = new NodeforStack<type>;
        newNode->data = key;
        newNode->next = top;
        top = newNode;
    }
    type pop(void)
    {
        if (!isEmpty())
        {
            NodeforStack<type> *tempNode = top;
            type tempData = tempNode->data;
            top = top->next;
            delete tempNode;
            return tempData;
        }
        std::cout << "Stack Underflow!\n";
        exit(EXIT_FAILURE);
    }
    type stackTop(void)
    {
        if (!isEmpty())
        {
            return top->data;
        }
        std::cout << "Stack Underflow!\n";
        exit(EXIT_FAILURE);
    }
    type stackBottom(void)
    {
        if (!isEmpty())
        {
            NodeforStack<type> *tempNode = top;
            while (tempNode->next)
            {
                tempNode = tempNode->next;
            }
            return tempNode->data;
        }
        std::cout << "Stack Underflow!\n";
        exit(EXIT_FAILURE);
    }
};
#endif