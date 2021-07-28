#ifndef BINARY_TREE_ADT
#define BINARY_TREE_ADT
#include "Queue_ADT.cpp"

template <class type>
class NodeForBinaryTree
{
public:
    type data;
    NodeForBinaryTree<type> *left;
    NodeForBinaryTree<type> *right;
    NodeForBinaryTree(type key) { data = key, left = right = NULL; }
};

template <class type>
class BinaryTree
{
private:
    NodeForBinaryTree<type> *root;
    Queue<NodeForBinaryTree<type> *> nodeQueue;

public:
    BinaryTree(void) { root = NULL; }
    void insert(type key)
    {
        if (!root)
        {
            root = new NodeForBinaryTree<type>(key);
            nodeQueue.enqueue(root);
            return;
        }
        while (true)
        {
            if (!nodeQueue.front()->left)
            {
                nodeQueue.front()->left = new NodeForBinaryTree<type>(key);
                nodeQueue.enqueue(nodeQueue.front()->left);
                return;
            }
            else if (!nodeQueue.front()->right)
            {
                nodeQueue.front()->right = new NodeForBinaryTree<type>(key);
                nodeQueue.enqueue(nodeQueue.front()->right);
                return;
            }
            else
            {
                nodeQueue.dequeue();
            }
        }
    }
    void preOrderTraversal(void)
    {
        preOrderTraversal(root);
        std::cout << '\n';
    }
    void preOrderTraversal(NodeForBinaryTree<type> *root)
    {
        if (root)
        {
            std::cout << root->data << ' ';
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }
    void inOrderTraversal(void)
    {
        inOrderTraversal(root);
        std::cout << '\n';
    }
    void inOrderTraversal(NodeForBinaryTree<type> *root)
    {
        if (root)
        {
            inOrderTraversal(root->left);
            std::cout << root->data << ' ';
            inOrderTraversal(root->right);
        }
    }
    void postOrderTraversal(void)
    {
        postOrderTraversal(root);
        std::cout << '\n';
    }
    void postOrderTraversal(NodeForBinaryTree<type> *root)
    {
        if (root)
        {
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            std::cout << root->data << ' ';
        }
    }
};
#endif