#ifndef STACK_ADT
#define STACK_ADT
template <class type>
class NodeForStack
{
public:
    type data;
    NodeForStack<type> *next;
};

template <class type>
class Stack
{
private:
    NodeForStack<type> *top;

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
            top = new NodeForStack<type>;
            top->data = key;
            top->next = NULL;
            return;
        }
        NodeForStack<type> *newNode = new NodeForStack<type>;
        newNode->data = key;
        newNode->next = top;
        top = newNode;
    }
    type pop(void)
    {
        if (!isEmpty())
        {
            NodeForStack<type> *tempNode = top;
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
            NodeForStack<type> *tempNode = top;
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