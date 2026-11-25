#ifndef UTILS_H
#define UTILS_H

#include <vector>

void BuildBalancedOrder(const std::vector<int>&, int, int, std::vector<int>&);

std::vector<int> GenerateBalancedOrder(const std::vector<int>&);

std::vector<int> GenerateKeys(int);

std::vector<int>
GenerateBalancedTernaryOrder(const std::vector<int>&);



#endif