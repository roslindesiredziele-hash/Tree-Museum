#include "BST.h"

#include <iostream>

double BenchmarkRandomBST(int n);

int main()
{
    BST tree;

auto keys =
{
    1,2,3,4,5,6,7,9,8
};

auto order = GenerateBalancedOrder(keys);

for(int x : order)
{
    std::cout << x << ' ';

    tree.insert(x);
}

std::cout << std::endl;

std::cout << tree.height() <<"\n"<< tree.size() <<"\n"<< tree.empty() <<  std::endl;

auto key = GenerateKeys(15);

auto balanced = GenerateBalancedOrder(key);

for(int x : balanced)
{
    std::cout << x << ' ';
}

std::cout << tree.height() <<"\n"<< tree.size() <<"\n"<< tree.empty() <<  std::endl;

}