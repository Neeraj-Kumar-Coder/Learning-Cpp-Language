#include <iostream>
// #include "Stack_ADT.cpp"
// #include "Queue_ADT.cpp"
// #include "Binary_Tree_ADT.cpp"
// #include "Doubly_Linked_List_ADT.cpp"
// #include "Binary_Search_Tree_ADT.cpp"
#include "AVL_Tree_ADT.cpp"

using namespace std;

int main(void)
{
    /*
    // STACK TESTING...
    Stack<int> stk;
    // cout << "The top element of the stack is: " << stk.stackTop() << '\n';
    // cout << "The bottom element of the stack is: " << stk.stackBottom() << '\n';

    stk.push(61);
    cout << "The top element of the stack is: " << stk.stackTop() << '\n';
    cout << "The bottom element of the stack is: " << stk.stackBottom() << '\n';

    stk.push(54);
    stk.push(33);
    cout << "The top element of the stack is: " << stk.stackTop() << '\n';
    cout << "The bottom element of the stack is: " << stk.stackBottom() << '\n';

    cout << "The popped element is: " << stk.pop() << '\n';
    cout << "The top element of the stack is: " << stk.stackTop() << '\n';
    cout << "The bottom element of the stack is: " << stk.stackBottom() << '\n';
    */

    /*
    // QUEUE TESTING...
    Queue<int> que;

    que.enqueue(5);
    cout << "The front element of the queue is: " << que.front() << '\n';
    cout << "The rear element of the queue is: " << que.rear() << '\n';

    que.enqueue(78);
    que.enqueue(86);
    cout << "The front element of the queue is: " << que.front() << '\n';
    cout << "The rear element of the queue is: " << que.rear() << '\n';

    que.dequeue();
    cout << "The front element of the queue is: " << que.front() << '\n';
    cout << "The rear element of the queue is: " << que.rear() << '\n';
    */

    /* 
    // BINARY TREE TESTING...
    BinaryTree<int> tree;
    for (int i = 1; i <= 10; i++)
        tree.insert(i);
    tree.preOrderTraversal();
    tree.inOrderTraversal();
    tree.postOrderTraversal();
    */

    /*
    // Doubly Linked List Testing...
    DoublyLinkedList<int> list;
    for (int i = 0; i < 10; i++)
    {
        list.insert(i);
    }
    list.deleteKey(9);
    list.traverse();
    */

    /* 
    BinarySearchTree<int> tree;
    int number, key;
    cout << "Enter the number of keys: ";
    cin >> number;
    while (number--)
    {
        cout << "Enter the key: ";
        cin >> key;
        tree.insert(key);
    }
    tree.inOrderTraversal();
    cout << "Enter the key you want to delete: ";
    cin >> key;
    tree.deleteNode(key);
    tree.inOrderTraversal();
    */

    AVLTree<int> tree;
    int number, key;
    cout << "Enter the number of keys you want to add to the AVL Tree: ";
    cin >> number;
    while (number--)
    {
        cout << "Enter the key: ";
        cin >> key;
        tree.insert(key);
    }
    tree.inOrderTraversal();
    tree.preOrderTraversal();
    tree.postOrderTraversal();
    cout << "Enter the key you want to search for: ";
    cin >> key;
    NodeForAVLTree<int> *node = tree.search(key);
    if (node)
    {
        cout << "The key is found with the value: " << node->data << '\n';
    }
    else
    {
        cout << "The key is NOT found!\n";
    }
    cout << "Enter the key you want to delete: ";
    cin >> key;
    tree.deleteNode(key);
    tree.inOrderTraversal();
    tree.preOrderTraversal();
    tree.postOrderTraversal();
    cout << "Enter the key you want to delete: ";
    cin >> key;
    tree.deleteNode(key);
    tree.inOrderTraversal();
    tree.preOrderTraversal();
    tree.postOrderTraversal();
    cout << "Enter the key you want to delete: ";
    cin >> key;
    tree.deleteNode(key);
    tree.inOrderTraversal();
    tree.preOrderTraversal();
    tree.postOrderTraversal();
    cout << "Enter the key you want to delete: ";
    cin >> key;
    tree.deleteNode(key);
    tree.inOrderTraversal();
    tree.preOrderTraversal();
    tree.postOrderTraversal();
    return 0;
}