#ifndef TERNARYTREE_H
#define TERNARYTREE_H

class TernaryTree
{
private:

    struct Node
    {
        int leftKey;
        int rightKey;

        bool hasSecondKey;

        Node* left;
        Node* middle;
        Node* right;
    };

    Node* root;

    int nodeCount;

    void insert(Node*&, int);

    void destroy(Node*);

    int height(Node*) const;

    bool contains(Node* node, int key) const;

public:

    TernaryTree();

    ~TernaryTree();

    void insert(int);

    int height() const;

    int size() const;

    bool empty() const;
};

#endif