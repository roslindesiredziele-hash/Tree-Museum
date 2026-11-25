#include "TernaryTree.h"

#include <algorithm>

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

    destroy(node -> left);
    destroy(node -> middle);
    destroy(node -> right);

    delete node;
}

void TernaryTree::insert(int key)
{
    insert(root, key);
}

void TernaryTree::insert(Node*& node, int key)
{
    if(node == nullptr)
    {
        node = new Node;

        node -> leftKey = key;

        node -> hasSecondKey = false;

        node -> left = nullptr;
        node -> middle = nullptr;
        node -> right = nullptr;

        ++nodeCount;

        return;
    }

    // node has space

    if(!node -> hasSecondKey)
    {
        if(key == node -> leftKey)
        {
            return;
        }

        node -> rightKey = key;

        if(node -> rightKey < node -> leftKey)
        {
            std::swap(node -> leftKey, node -> rightKey);
        }

        node->hasSecondKey = true;

        ++nodeCount;

        return;
    }

    // full node

    if(key < node -> leftKey)
    {
        insert(node -> left, key);
    }
    else if(key > node -> rightKey)
    {
        insert(node -> right, key);
    }
    else
    {
        insert(node -> middle, key);
    }
}

int TernaryTree::height() const
{
    return height(root);
}

int TernaryTree::height(Node* node) const
{
    if(node == nullptr)
    {
        return 0;
    }

    return 1 +
        std::max(
            {
                height(node->left),
                height(node->middle),
                height(node->right)
            }
        );
}

