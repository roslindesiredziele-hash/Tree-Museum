#include "BST.h"

BST::BST():
     root(nullptr)
{

}

BST::~BST()
{
    destroy(root);
}

