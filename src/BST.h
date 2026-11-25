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

    int nodeCount;

    void insert(Node*&, int);

    int height(const Node*) const;

    void destroy(Node*);

    void remove(Node*&, int);

    Node* findMin(Node*) const;

    public:

    BST();

    ~BST();

    void insert(int);

    int height() const;

    int size() const;

    bool empty() const;

    void remove(int);
};

#endif