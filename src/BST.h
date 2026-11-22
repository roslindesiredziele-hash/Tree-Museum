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

    int height(Node*) const;

    void destroy(Node*);

    public:

    BST();

    ~BST();

    void insert(int);

    int height() const;
    
};
#endif