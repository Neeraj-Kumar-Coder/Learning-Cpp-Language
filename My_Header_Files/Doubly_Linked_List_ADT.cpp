#ifndef DOUBLY_LINKED_LIST_ADT
#define DOUBLY_LINKED_LIST_ADT
template <class type>
class NodeForDLL
{
public:
    type data;
    NodeForDLL *previous, *next;
    NodeForDLL(void) {}
    NodeForDLL(type data)
    {
        this->data = data;
        previous = next = NULL;
    }
    NodeForDLL(type data, NodeForDLL *previous, NodeForDLL *next)
    {
        this->data = data;
        this->previous = previous;
        this->next = next;
    }
};

template <class type>
class DoublyLinkedList
{
private:
    NodeForDLL<type> *head = NULL;

public:
    void insert(type key)
    {
        if (!head)
        {
            head = new NodeForDLL<type>(key);
            return;
        }
        NodeForDLL<type> *prev = NULL;
        NodeForDLL<type> *next = head;
        while (next)
        {
            prev = next;
            next = next->next;
        }
        prev->next = new NodeForDLL<type>(key, prev, next);
    }
    void deleteKey(type key)
    {
        if (!head)
        {
            return;
        }
        NodeForDLL<type> *temp = head;
        while (temp->data != key)
        {
            temp = temp->next;
        }
        if (!temp->previous)
        {
            head = head->next;
        }
        else if (!temp->next)
        {
            temp->previous->next = temp->next;
        }
        else
        {
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
        }
        delete temp;
    }
    void traverse(void)
    {
        NodeForDLL<type> *temp = head;
        while (temp)
        {
            std::cout << temp->data << ' ';
            temp = temp->next;
        }
        std::cout << '\n';
    }
};
#endif