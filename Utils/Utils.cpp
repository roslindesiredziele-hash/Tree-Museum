#include "Utils.h"

void BuildBalancedOrder(const std::vector<int>& sorted, int left, int right, std::vector<int>& order)
{
    if(left > right)
    {
        return;
    }

    int middle = left + (right - left) / 2;

    order.push_back(sorted[middle]);

    BuildBalancedOrder(sorted, left, middle - 1, order);

   BuildBalancedOrder(sorted, middle + 1, right, order);
}

std::vector<int> GenerateBalancedOrder(const std::vector<int>& sorted)
{
    std::vector<int> order;

    BuildBalancedOrder(sorted, 0, static_cast<int> (sorted.size()) - 1, order);

    return order;
}

std::vector<int> GenerateKeys(int n)
{
    std::vector<int> keys;

    for(int i = 1; i <= n; i++)
    {
        keys.push_back(i);
    }

    return keys;
}

void GenerateBalancedTernaryOrderRec(const std::vector<int>& keys, int left, int right, std::vector<int>& result)
{
    if(left > right)
    {
        return;
    }

    if(left == right)
    {
        result.push_back(keys[left]);

        return;
    }

    int length = right - left + 1;

    int third1 = left + length / 3;

    int third2 = left + (2 * length) / 3;

    if(third1 > right)
    {
        third1 = right;
    }

    if(third2 > right)
    {
        third2 = right;
    }

    result.push_back(keys[third1]);

    if(third2 != third1)
    {
        result.push_back(keys[third2]);
    }

    GenerateBalancedTernaryOrderRec(keys, left, third1 - 1, result);

    GenerateBalancedTernaryOrderRec(keys, third1 + 1, third2 - 1, result);

    GenerateBalancedTernaryOrderRec(keys, third2 + 1, right, result);
}