#include "AVL.h"

#include <algorithm>

AVL::AVL()
    : root(nullptr)
{
}

AVL::~AVL()
{
    destroy(root);
}

void AVL::destroy(Node* node)
{
    if(node == nullptr)
    {
        return;
    }

    destroy(node->left);
    destroy(node->right);

    delete node;
}

int AVL::height() const
{
    return height(root);
}

int AVL::height(Node* node) const
{
    if(node == nullptr)
    {
        return 0;
    }

    return node->height;
}

int AVL::getBalance(Node* node) const
{
    if(node == nullptr)
    {
        return 0;
    }

    return height(node->left) - height(node->right);
}

void AVL::updateHeight(Node* node)
{
    if(node == nullptr)
    {
        return;
    }

    node->height = 1 + std::max(height(node->left), height(node->right));
}

AVL::Node* AVL::rotateRight(Node* y)
{
    Node* x = y -> left;

    Node* T2 = x -> right;

    x -> right = y;

    y -> left = T2;

    updateHeight(y);

    updateHeight(x);

    return x;
}

AVL::Node* AVL::rotateLeft(Node* x)
{
    Node* y = x -> right;

    Node* T2 = y -> left;

    y -> left = x;

    x -> right = T2;

    updateHeight(x);

    updateHeight(y);

    return y;
}

void AVL::insert(int key)
{
    root = insert(root, key);
}

AVL::Node* AVL::insert(Node* node, int key)
{
    if(node == nullptr)
    {
        Node* newNode = new Node;

        newNode -> key = key;

        newNode -> height = 1;

        newNode -> left = nullptr;
        newNode -> right = nullptr;

        return newNode;
    }

    if(key < node -> key)
    {
        node -> left = insert(node -> left, key);
    }
    else if(key > node -> key)
    {
        node -> right = insert(node->right, key);
    }
    else
    {
        return node;
    }

    updateHeight(node);

    int balance =
        getBalance(node);

    // LL

    if(balance > 1 &&
       key < node->left->key)
    {
        return rotateRight(node);
    }

    // RR

    if(balance < -1 &&
       key > node->right->key)
    {
        return rotateLeft(node);
    }

    // LR

    if(balance > 1 &&
       key > node -> left -> key)
    {
        node -> left = rotateLeft(node -> left);

        return rotateRight(node);
    }

    // RL

    if(balance < -1 &&
       key < node -> right -> key)
    {
        node -> right = rotateRight(node -> right);

        return rotateLeft(node);
    }

    return node;
}

void AVL::remove(int key)
{
    root = remove(root, key);
}