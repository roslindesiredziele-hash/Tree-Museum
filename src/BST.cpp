#include "BST.h"

BST::BST():
     root(nullptr)
{

}

BST::~BST()
{
    destroy(root);
}

void BST::destroy(Node* node)
{
    if(node == nullptr)
    {
        return;
    }

    destroy(node -> left);
    destroy(node -> right);

    delete node;
}

void BST::insert(int key)
{
    insert(root, key);
}

void BST::insert(Node*& node, int key)
{
    if (node == nullptr)
    {
        node = new Node;

        node -> key = key;

        node -> left = nullptr;
        node -> right = nullptr;

        return;
    }

    if (key < node -> key)
    {
        insert(node -> left, key);
    }
    else if (key > node -> key)
    {
        insert(node -> right, key);
    }
}


int BST::height() const
{
    return height(root);
}

int BST::height(const Node* node) const
{
    if (node == nullptr)
    {
        return 0;
    }

    int leftHeight = height(node->left);

    int rightHeight = height(node->right);

    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }

    return rightHeight + 1;
}

int BST::size() const
{
    return size(root);
}

int BST::size(const Node* node) const
{
    if(node == nullptr)
    {
        return 0;
    }

    return 1 + size(node -> left) + size(node -> right);
}

bool BST::empty() const
{
    return root == nullptr;
}

void BST::remove(int key)
{
    remove(root, key);
}

