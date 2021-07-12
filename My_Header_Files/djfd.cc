#include <iostream>
#include "C:\Neeraj Kumar\Learning C++ Language\My_Header_Files\Linked_List_ADT.cpp"

using namespace std;

int main(void)
{
    LinkedList<int> a;
    // a.printList();
    a.insertSorted(534);
    // a.printList();
    a.insertSorted(525);
    // a.printList();
    a.insertSorted(53);
    // a.printList();
    a.insertSorted(53);
    // a.printList();
    a.insertSorted(23);
    // a.printList();
    a.insertSorted(5);
    a.printList();
    // a.printListReverse();
    a.deleteNode(534);
    a.printList();
    cout << "The length of the linked list is: " << a.lengthOfList() << '\n';
    return 0;
}