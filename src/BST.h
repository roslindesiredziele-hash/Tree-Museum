#ifndef BST_H
#define BST_H

class BST
{
    private:

    struct Node
    {
        int key;

        Node* left;
        Node* right;
    };

    Node* root;

    void insert(Node*&, int);

    
    
};
#endif