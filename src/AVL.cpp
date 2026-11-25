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