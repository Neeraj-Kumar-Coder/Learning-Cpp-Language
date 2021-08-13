#ifndef BINARY_SEARCH_TREE_ADT
#define BINARY_SEARCH_TREE_ADT
template <class type>
class NodeForBST
{
public:
    type data;
    NodeForBST<type> *left, *right;
    NodeForBST(type key)
    {
        data = key;
        left = right = NULL;
    }
};

template <class type>
class BinarySearchTree
{
private:
    NodeForBST<type> *root = NULL;

public:
    void insert(type key)
    {
        if (!root)
        {
            root = new NodeForBST<type>(key);
            return;
        }
        NodeForBST<type> *parent = NULL;
        NodeForBST<type> *cur = root;
        while (cur)
        {
            parent = cur;
            if (cur->data < key)
            {
                cur = cur->right;
            }
            else if (cur->data > key)
            {
                cur = cur->left;
            }
            else // Nodes in a BST is unique
            {
                return;
            }
        }
        if (parent->data < key)
        {
            parent->right = new NodeForBST<type>(key);
        }
        else
        {
            parent->left = new NodeForBST<type>(key);
        }
    }
    NodeForBST<type> *search(type key)
    {
        NodeForBST<type> *temp = root;
        while (temp)
        {
            if (temp->data > key)
            {
                temp = temp->left;
            }
            else if (temp->data < key)
            {
                temp = temp->right;
            }
            else
            {
                return temp;
            }
        }
        return temp;
    }
    NodeForBST<type> *inOrderSuccessor(NodeForBST<type> *node)
    {
        node = node->right;
        while (node->left)
        {
            node = node->left;
        }
        return node;
    }
    void deleteNode(type key)
    {
        NodeForBST<type> *node = search(key);
        if (!node->left && !node->right)
        {
            delete node;
        }
        else if (!node->left ^ !node->right)
        {
            node->left ? *node = *(node->left) : *node = *(node->right);
        }
        else
        {
            NodeForBST<type> *successor = inOrderSuccessor(node);
            node->data = successor->data;
            deleteNode(successor);
        }
    }
    void deleteNode(NodeForBST<type> *node)
    {
        if (!node->left && !node->right)
        {
            delete node;
        }
        else if (!node->left ^ !node->right)
        {
            node->left ? *node = *(node->left) : *node = *(node->right);
        }
        else
        {
            NodeForBST<type> *successor = inOrderSuccessor(node->right);
            node->data = successor->data;
            deleteNode(successor);
        }
    }
    void inOrderTraversal(void)
    {
        inOrderTraversal(root);
        std::cout << '\n';
    }
    void inOrderTraversal(NodeForBST<type> *node)
    {
        if (node)
        {
            inOrderTraversal(node->left);
            std::cout << node->data << ' ';
            inOrderTraversal(node->right);
        }
    }
    void preOrderTraversal(void)
    {
        preOrderTraversal(root);
        std::cout << '\n';
    }
    void preOrderTraversal(NodeForBST<type> *node)
    {
        if (node)
        {
            std::cout << node->data << ' ';
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }
    void postOrderTraversal(void)
    {
        postOrderTraversal(root);
        std::cout << '\n';
    }
    void postOrderTraversal(NodeForBST<type> *node)
    {
        if (node)
        {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            std::cout << node->data << ' ';
        }
    }
};
#endif