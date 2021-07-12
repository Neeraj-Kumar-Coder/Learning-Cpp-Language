#ifndef LINKED_LIST_ADT
#define LINKED_LIST_ADT
template <class type>
class Node
{
public:
    type data;
    Node<type> *next;
};

template <class type>
class LinkedList
{
private:
    Node<type> *head;

public:
    LinkedList(void) { head = NULL; }
    void insert(type key)
    {
        if (!head)
        {
            head = new Node<type>;
            head->data = key;
            head->next = NULL;
            return;
        }
        Node<type> *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new Node<type>;
        temp->next->data = key;
        temp->next->next = NULL;
    }
    void insertSorted(type key)
    {
        if (!head)
        {
            head = new Node<type>;
            head->data = key;
            head->next = NULL;
            return;
        }
        Node<type> *temp = head;
        while (temp->next && temp->next->data < key)
        {
            temp = temp->next;
        }
        if (temp == head)
        {
            if (temp->data > key)
            {
                Node<type> *newNode = new Node<type>;
                newNode->data = key;
                newNode->next = temp;
                head = newNode;
            }
            else
            {
                Node<type> *newNode = new Node<type>;
                newNode->data = key;
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
        else
        {
            Node<type> *newNode = new Node<type>;
            newNode->data = key;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void deleteNode(type key)
    {
        Node<type> *previous = NULL;
        Node<type> *current = head;
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
            Node<type> *previousNode = NULL;
            Node<type> *currentNode = head;
            Node<type> *nextNode = head->next;
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
        Node<type> *temp = head;
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
        Node<type> *temp = head;
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
    void printListReverse(Node<type> *head)
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