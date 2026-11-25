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
