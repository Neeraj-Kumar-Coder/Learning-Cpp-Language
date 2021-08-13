#ifndef AVL_TREE_ADT
#define AVL_TREE_ADT
template <class type>
class NodeForAVLTree
{
public:
    int height;
    type data;
    NodeForAVLTree<type> *left, *right;
    NodeForAVLTree(void) {}
    NodeForAVLTree(type key)
    {
        data = key;
        height = 0;
        left = right = NULL;
    }
};

template <class type>
class AVLTree
{
private:
    NodeForAVLTree<type> *root;
    int heightCalculate(NodeForAVLTree<type> *node)
    {
        int leftHeight, rightHeight;
        if (!node)
        {
            return -1;
        }
        leftHeight = !node->left ? -1 : node->left->height;
        rightHeight = !node->right ? -1 : node->right->height;
        return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
    }
    int balanceFactor(NodeForAVLTree<type> *node)
    {
        return heightCalculate(node->right) - heightCalculate(node->left);
    }
    NodeForAVLTree<type> *LLRotation(NodeForAVLTree<type> *node)
    {
        NodeForAVLTree<type> *newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        return newRoot;
    }
    NodeForAVLTree<type> *RRRotation(NodeForAVLTree<type> *node)
    {
        NodeForAVLTree<type> *newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        return newRoot;
    }
    NodeForAVLTree<type> *LRRotation(NodeForAVLTree<type> *node)
    {
        NodeForAVLTree<type> *newRoot = node->left->right;
        node->left->right = newRoot->left;
        newRoot->left = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        return newRoot;
    }
    NodeForAVLTree<type> *RLRotation(NodeForAVLTree<type> *node)
    {
        NodeForAVLTree<type> *newRoot = node->right->left;
        node->right->left = newRoot->right;
        newRoot->right = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        return newRoot;
    }
    NodeForAVLTree<type> *inOrderSuccessor(NodeForAVLTree<type> *node)
    {
        node = node->right;
        while (node->left)
        {
            node = node->left;
        }
        return node;
    }
    NodeForAVLTree<type> *inOrderPredecessor(NodeForAVLTree<type> *node)
    {
        node = node->left;
        while (node->right)
        {
            node = node->right;
        }
        return node;
    }

public:
    AVLTree(void) { root = NULL; }
    void insert(type key)
    {
        if (!root)
        {
            root = new NodeForAVLTree<type>(key);
            return;
        }
        root = insert(root, key);
    }
    NodeForAVLTree<type> *insert(NodeForAVLTree<type> *node, type key)
    {
        if (!node->left && node->data > key)
        {
            node->left = new NodeForAVLTree<type>(key);
            return node;
        }
        if (!node->right && node->data < key)
        {
            node->right = new NodeForAVLTree<type>(key);
            return node;
        }

        if (node->data > key)
        {
            node->left = insert(node->left, key);
        }
        else if (node->data < key)
        {
            node->right = insert(node->right, key);
        }
        else
        {
            return node;
        }
        node->height = heightCalculate(node);

        if (balanceFactor(node) == -2 && balanceFactor(node->left) == -1)
        {
            NodeForAVLTree<type> *newRoot = LLRotation(node);
            if (newRoot->left)
                newRoot->left->height = heightCalculate(newRoot->left);
            if (newRoot->right)
                newRoot->right->height = heightCalculate(newRoot->right);
            newRoot->height = heightCalculate(newRoot);
            return newRoot;
        }
        else if (balanceFactor(node) == 2 && balanceFactor(node->right) == 1)
        {
            NodeForAVLTree<type> *newRoot = RRRotation(node);
            if (newRoot->left)
                newRoot->left->height = heightCalculate(newRoot->left);
            if (newRoot->right)
                newRoot->right->height = heightCalculate(newRoot->right);
            newRoot->height = heightCalculate(newRoot);
            return newRoot;
        }
        else if (balanceFactor(node) == -2 && balanceFactor(node->left) == 1)
        {
            NodeForAVLTree<type> *newRoot = LRRotation(node);
            if (newRoot->left)
                newRoot->left->height = heightCalculate(newRoot->left);
            if (newRoot->right)
                newRoot->right->height = heightCalculate(newRoot->right);
            newRoot->height = heightCalculate(newRoot);
            return newRoot;
        }
        else if (balanceFactor(node) == 2 && balanceFactor(node->right) == -1)
        {
            NodeForAVLTree<type> *newRoot = RLRotation(node);
            if (newRoot->left)
                newRoot->left->height = heightCalculate(newRoot->left);
            if (newRoot->right)
                newRoot->right->height = heightCalculate(newRoot->right);
            newRoot->height = heightCalculate(newRoot);
            return newRoot;
        }
        return node;
    }
    NodeForAVLTree<type> *search(type key)
    {
        NodeForAVLTree<type> *node = root;
        while (node)
        {
            if (node->data > key)
            {
                node = node->left;
            }
            else if (node->data < key)
            {
                node = node->right;
            }
            else
            {
                return node;
            }
        }
        return node;
    }
    void deleteNode(type key)
    {
        if (search(key))
        {
            root = deleteNode(root, key);
        }
        else
        {
            std::cout << "Key not found!! Enter a valid key\n";
        }
    }
    NodeForAVLTree<type> *deleteNode(NodeForAVLTree<type> *node, type key)
    {
        if (node->data == key)
        {
            if (!node->left && !node->right)
            {
                delete node;
                return NULL;
            }
            else if (!node->left ^ !node->right)
            {
                *(node) = node->left ? *(node->left) : *(node->right);
                return node;
            }
            else
            {
                if (balanceFactor(node) >= 0)
                {
                    NodeForAVLTree<type> *successor = inOrderSuccessor(node);
                    node->data = successor->data;
                    node->right = deleteNode(node->right, successor->data);
                }
                else
                {
                    NodeForAVLTree<type> *predecessor = inOrderPredecessor(node);
                    node->data = predecessor->data;
                    node->left = deleteNode(node->left, predecessor->data);
                }
                node->height = heightCalculate(node);
                return node;
            }
        }
        else if (node->data > key)
        {
            node->left = deleteNode(node->left, key);
        }
        else if (node->data < key)
        {
            node->right = deleteNode(node->right, key);
        }
        node->height = heightCalculate(node);

        if (balanceFactor(node) == -2 && balanceFactor(node->left) == -1)
        {
            NodeForAVLTree<type> *newRoot = LLRotation(node);
            if (newRoot->left)
                newRoot->left->height = heightCalculate(newRoot->left);
            if (newRoot->right)
                newRoot->right->height = heightCalculate(newRoot->right);
            newRoot->height = heightCalculate(newRoot);
            return newRoot;
        }
        else if (balanceFactor(node) == 2 && balanceFactor(node->right) == 1)
        {
            NodeForAVLTree<type> *newRoot = RRRotation(node);
            if (newRoot->left)
                newRoot->left->height = heightCalculate(newRoot->left);
            if (newRoot->right)
                newRoot->right->height = heightCalculate(newRoot->right);
            newRoot->height = heightCalculate(newRoot);
            return newRoot;
        }
        else if (balanceFactor(node) == -2 && balanceFactor(node->left) == 1)
        {
            NodeForAVLTree<type> *newRoot = LRRotation(node);
            if (newRoot->left)
                newRoot->left->height = heightCalculate(newRoot->left);
            if (newRoot->right)
                newRoot->right->height = heightCalculate(newRoot->right);
            newRoot->height = heightCalculate(newRoot);
            return newRoot;
        }
        else if (balanceFactor(node) == 2 && balanceFactor(node->right) == -1)
        {
            NodeForAVLTree<type> *newRoot = RLRotation(node);
            if (newRoot->left)
                newRoot->left->height = heightCalculate(newRoot->left);
            if (newRoot->right)
                newRoot->right->height = heightCalculate(newRoot->right);
            newRoot->height = heightCalculate(newRoot);
            return newRoot;
        }
        return node;
    }
    void inOrderTraversal(void)
    {
        inOrderTraversal(root);
        std::cout << '\n';
    }
    void inOrderTraversal(NodeForAVLTree<type> *node)
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
    void preOrderTraversal(NodeForAVLTree<type> *node)
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
    void postOrderTraversal(NodeForAVLTree<type> *node)
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