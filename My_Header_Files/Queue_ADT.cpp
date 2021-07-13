#ifndef QUEUE_ADT
#define QUEUE_ADT
template <class type>
class NodeforQueue
{
public:
    type data;
    NodeforQueue<type> *next;
};

template <class type>
class Queue
{
private:
    NodeforQueue<type> *frontInd;
    NodeforQueue<type> *backInd;

public:
    Queue(void) { frontInd = backInd = NULL; }
    void enqueue(type key)
    {
        if (!backInd)
        {
            backInd = new NodeforQueue<type>;
            frontInd = backInd;
            backInd->data = key;
            backInd->next = NULL;
            return;
        }
        backInd->next = new NodeforQueue<type>;
        backInd->next->data = key;
        backInd->next->next = NULL;
        backInd = backInd->next;
    }
    type dequeue(void)
    {
        if (frontInd)
        {
            NodeforQueue<type> *tempNode = frontInd;
            type tempData = tempNode->data;
            frontInd = frontInd->next;
            delete tempNode;
            return tempData;
        }
        std::cout << "The queue is Empty!\n";
        exit(EXIT_FAILURE);
    }
    type front(void)
    {
        if (frontInd)
        {
            return frontInd->data;
        }
        std::cout << "The queue is Empty!\n";
        exit(EXIT_FAILURE);
    }
    type rear(void)
    {
        if (backInd)
        {
            return backInd->data;
        }
        std::cout << "The queue is Empty!\n";
        exit(EXIT_FAILURE);
    }
};
#endif