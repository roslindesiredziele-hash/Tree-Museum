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

public:

    TernaryTree();

    ~TernaryTree();

    void insert(int);

    void remove(int);

    int height() const;

    int size() const;
};

#endif