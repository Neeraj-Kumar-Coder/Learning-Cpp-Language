#include <iostream>
// #include "Stack_ADT.cpp"
// #include "Queue_ADT.cpp"
#include "Binary_Tree_ADT.cpp"

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

    // BINARY TREE TESTING...
    BinaryTree<int> tree;
    for (int i = 1; i <= 10; i++)
        tree.insert(i);
    tree.preOrderTraversal();
    tree.inOrderTraversal();
    tree.postOrderTraversal();

    return 0;
}