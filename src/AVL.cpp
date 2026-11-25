#include "AVL.h"

#include <algorithm>
#include <iostream>

AVL::AVL()
    : root(nullptr),
      nodeCount(0)
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

int AVL::size() const
{
    return nodeCount;
}

bool AVL::empty() const
{
    return root == nullptr;
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

    return node -> nodeHeight;
}

int AVL::getBalance(Node* node) const
{
    if(node == nullptr)
    {
        return 0;
    }

    return height(node -> left) - height(node -> right);
}

void AVL::updateHeight(Node* node)
{
    if(node == nullptr)
    {
        return;
    }

    node -> nodeHeight = 1 + std::max(height(node -> left), height(node -> right));
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

void AVL::insert(int key)
{
    root = insert(root, key);
}

AVL::Node* AVL::insert(Node* node, int key)
{
    if(node == nullptr)
    {
        Node* newNode = new Node;

        newNode -> key = key;

        newNode -> nodeHeight = 1;

        newNode -> left = nullptr;
        newNode -> right = nullptr;

        ++nodeCount;

        return newNode;
    }

    if(key < node -> key)
    {
        node -> left = insert(node -> left, key);
    }
    else if(key > node -> key)
    {
        node -> right = insert(node->right, key);
    }
    else
    {
        return node;
    }

    updateHeight(node);

    int balance =
        getBalance(node);

    // LL

    if(balance > 1 &&
       key < node->left->key)
    {
        return rotateRight(node);
    }

    // RR

    if(balance < -1 &&
       key > node->right->key)
    {
        return rotateLeft(node);
    }

    // LR

    if(balance > 1 &&
       key > node -> left -> key)
    {
        node -> left = rotateLeft(node -> left);

        return rotateRight(node);
    }

    // RL

    if(balance < -1 &&
       key < node -> right -> key)
    {
        node -> right = rotateRight(node -> right);

        return rotateLeft(node);
    }

    return node;
}

void AVL::remove(int key)
{
    root = remove(root, key);
}

AVL::Node* AVL::findMin(Node* node)
{
    while(node -> left != nullptr)
    {
        node = node -> left;
    }

    return node;
}

AVL::Node* AVL::remove(Node* node, int key)
{
    if(node == nullptr)
    {
        return nullptr;
    }

    if(key < node -> key)
    {
        node->left = remove(node -> left, key);
    }
    else if(key > node -> key)
    {
        node -> right = remove(node -> right, key);
    }
    else
    {
        // no children

        if(node -> left == nullptr &&
           node -> right == nullptr)
        {
            delete node;

            --nodeCount;

            return nullptr;
        }

        // only right child

        if(node -> left == nullptr)
        {
            Node* child =
                node -> right;

            delete node;

            --nodeCount;

            return child;
        }

        // only left child

        if(node -> right == nullptr)
        {
            Node* child =
                node -> left;

            delete node;

            --nodeCount;

            return child;
        }

        // two children

        Node* successor = findMin(node -> right);

        node -> key = successor -> key;

        node -> right = remove( node -> right, successor -> key);
    }

    updateHeight(node);

    int balance = getBalance(node);

    // LL

    if(balance > 1 && getBalance(node -> left) >= 0)
    {
        return rotateRight(node);
    }

    // LR

    if(balance > 1 && getBalance(node -> left) < 0)
    {
        node -> left =
            rotateLeft(node -> left);

        return rotateRight(node);
    }

    // RR

    if(balance < -1 && getBalance(node -> right) <= 0)
    {
        return rotateLeft(node);
    }

    // RL

    if(balance < -1 && getBalance(node -> right) > 0)
    {
        node -> right = rotateRight(node -> right);

        return rotateLeft(node);
    }

    return node;
}

bool AVL::contains(int key) const
{
    return contains(root, key);
}

bool AVL::contains(Node* node, int key) const
{
    if(node == nullptr)
    {
        return false;
    }

    if(key == node -> key)
    {
        return true;
    }

    if(key < node -> key)
    {
        return contains(node -> left, key);
    }

    return contains(node -> right, key);
}

void AVL::inorder() const
{
    inorder(root);

    std::cout << '\n';
}

void AVL::inorder(Node* node) const
{
    if(node == nullptr)
    {
        return;
    }

    inorder(node -> left);

    std::cout << node -> key << ' ';

    inorder(node -> right);
}