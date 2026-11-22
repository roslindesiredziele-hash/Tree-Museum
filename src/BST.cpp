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

