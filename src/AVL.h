#ifndef AVL_H
#define AVL_H

class AVL
{
private:

    struct Node
    {
        int key;

        int height;

        Node* left;
        Node* right;
    };

    Node* root;

    void insert(Node*&, int);

    void destroy(Node*);

    int height(Node*) const;

    int getBalance(Node*) const;

    void updateHeight(Node*);

    Node* rotateLeft(Node*);

    Node* rotateRight(Node*);

public:

    AVL();

    ~AVL();

    void insert(int);

    int height() const;
};

#endif