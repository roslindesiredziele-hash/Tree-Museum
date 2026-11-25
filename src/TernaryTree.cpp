#include "TernaryTree.h"

TernaryTree::TernaryTree()
    : root(nullptr),
      nodeCount(0)
{
}

TernaryTree::~TernaryTree()
{
    destroy(root);
}

void TernaryTree::destroy(Node* node)
{
    if(node == nullptr)
    {
        return;
    }

    destroy(node->left);
    destroy(node->middle);
    destroy(node->right);

    delete node;
}

void TernaryTree::insert(int key)
{
    insert(root, key);
}

