#ifndef AVL_H
#define AVL_H

class AVL
{
private:

    struct Node
    {
        int key;

        int nodeHeight;

        Node* left;
        Node* right;
    };

    Node* root;

    int nodeCount;

    Node* insert(Node*, int);

    Node* remove(Node*, int);

    void destroy(Node*);

    int height(Node*) const;

    int getBalance(Node*) const;

    void updateHeight(Node*);

    Node* rotateLeft(Node*);

    Node* rotateRight(Node*);

    Node* findMin(Node*);

    bool contains(Node*, int) const;

    void inorder(Node*) const;

public:

    AVL();

    ~AVL();

    void insert(int);

    int height() const;

    void remove(int);

    int size() const;

    bool empty() const;
    
    bool contains(int) const;

    void inorder() const;
};

#endif