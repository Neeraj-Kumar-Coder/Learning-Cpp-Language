#ifndef LINKED_LIST_ADT
#define LINKED_LIST_ADT
template <class type>
class NodeForLinkedList
{
public:
    type data;
    NodeForLinkedList<type> *next;
};

template <class type>
class LinkedList
{
private:
    NodeForLinkedList<type> *head;

public:
    LinkedList(void) { head = NULL; }
    void insert(type key)
    {
        if (!head)
        {
            head = new NodeForLinkedList<type>;
            head->data = key;
            head->next = NULL;
            return;
        }
        NodeForLinkedList<type> *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new NodeForLinkedList<type>;
        temp->next->data = key;
        temp->next->next = NULL;
    }
    void insertSorted(type key)
    {
        if (!head)
        {
            head = new NodeForLinkedList<type>;
            head->data = key;
            head->next = NULL;
            return;
        }
        NodeForLinkedList<type> *temp = head;
        while (temp->next && temp->next->data < key)
        {
            temp = temp->next;
        }
        if (temp == head)
        {
            if (temp->data > key)
            {
                NodeForLinkedList<type> *newNode = new NodeForLinkedList<type>;
                newNode->data = key;
                newNode->next = temp;
                head = newNode;
            }
            else
            {
                NodeForLinkedList<type> *newNode = new NodeForLinkedList<type>;
                newNode->data = key;
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
        else
        {
            NodeForLinkedList<type> *newNode = new NodeForLinkedList<type>;
            newNode->data = key;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void deleteNode(type key)
    {
        NodeForLinkedList<type> *previous = NULL;
        NodeForLinkedList<type> *current = head;
        while (current && current->data != key)
        {
            previous = current;
            current = current->next;
        }
        if (!previous)
        {
            head = current->next;
            delete current;
        }
        else if (!current)
        {
            std::cout << "Key not found!\n";
        }
        else
        {
            previous->next = current->next;
            delete current;
        }
    }
    void reverse(void)
    {
        if (head)
        {
            NodeForLinkedList<type> *previousNode = NULL;
            NodeForLinkedList<type> *currentNode = head;
            NodeForLinkedList<type> *nextNode = head->next;
            while (nextNode)
            {
                currentNode->next = previousNode;
                previousNode = currentNode;
                currentNode = nextNode;
                nextNode = nextNode->next;
            }
            currentNode->next = previousNode;
            head = currentNode;
        }
    }
    void printList(void)
    {
        NodeForLinkedList<type> *temp = head;
        while (temp)
        {
            std::cout << temp->data << ' ';
            temp = temp->next;
        }
        std::cout << '\n';
    }
    size_t lengthOfList(void)
    {
        size_t length = 0;
        NodeForLinkedList<type> *temp = head;
        while (temp)
        {
            length++;
            temp = temp->next;
        }
        return length;
    }
    void printListReverse(void)
    {
        printListReverse(head);
        std::cout << '\n';
    }
    void printListReverse(NodeForLinkedList<type> *head)
    {
        if (!head)
        {
            return;
        }
        printListReverse(head->next);
        std::cout << head->data << ' ';
    }
};
#endif