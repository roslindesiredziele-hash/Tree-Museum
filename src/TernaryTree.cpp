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

