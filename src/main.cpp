#include "BST.h"

#include <iostream>

int main()
{
    BST tree;

auto keys =
{
    1,2,3,4,5,6,7
};

auto order = GenerateBalancedOrder(keys);

for(int x : order)
{
    std::cout << x << ' ';

    tree.insert(x);
}

std::cout << std::endl;

std::cout << tree.height() << std::endl;

}