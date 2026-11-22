#include "BST.h"

#include <vector>

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

void BST::insert(int key)
{
    insert(root, key);
}

void BST::insert(Node*& node, int key)
{
    if (node == nullptr)
    {
        node = new Node;

        node -> key = key;

        node -> left = nullptr;
        node -> right = nullptr;

        return;
    }

    if (key < node -> key)
    {
        insert(node -> left, key);
    }
    else if (key > node -> key)
    {
        insert(node -> right, key);
    }
}


int BST::height() const
{
    return height(root);
}

int BST::height(Node* node) const
{
    if (node == nullptr)
    {
        return 0;
    }

    int leftHeight = height(node->left);

    int rightHeight = height(node->right);

    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }

    return rightHeight + 1;
}

bool BST::empty() const
{
    return root == nullptr;
}

void BuildBalancedOrder(const std::vector<int>& sorted, int left, int right, std::vector<int>& order)
{
    if(left > right)
    {
        return;
    }

    int middle = (left + right) / 2;

    order.push_back(sorted[middle]);

    BuildBalancedOrder(sorted, left, middle - 1, order);

   BuildBalancedOrder(sorted, left, middle + 1, order);
}