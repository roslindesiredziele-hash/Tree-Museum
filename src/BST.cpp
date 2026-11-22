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

        node->key = key;

        node->left = nullptr;
        node->right = nullptr;

        return;
    }

    if (key < node->key)
    {
        insert(node->left, key);
    }
    else if (key > node->key)
    {
        insert(node->right, key);
    }
}

