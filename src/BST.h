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

    int size() const;

    bool empty() const;
};

void BuildBalancedOrder(const std::vector<int>&, int, int, std::vector<int>&);

std::vector<int> GenerateBalancedOrder(const std::vector<int>&);

#endif