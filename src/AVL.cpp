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