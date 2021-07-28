#include <iostream>
#include "C:\Neeraj Kumar\Learning C++ Language\My_Header_Files\Binary_Tree_ADT.cpp"

using namespace std;

int main(void)
{
    BinaryTree<int> btree;
    int choice;
    while (true)
    {
        cout << "Enter the element you want to add to the Binary Tree (ENTER 0 TO EXIT): ";
        cin >> choice;
        if (choice)
        {
            btree.insert(choice);
            continue;
        }
        break;
    }
    cout << "Inorder Traversal: ";
    btree.inOrderTraversal();
    cout << "Preorder Traversal: ";
    btree.preOrderTraversal();
    cout << "Postorder Traversal: ";
    btree.postOrderTraversal();
    return 0;
}