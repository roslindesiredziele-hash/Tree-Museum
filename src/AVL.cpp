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


