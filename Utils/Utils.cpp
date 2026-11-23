#include "Utils.h"

#include <vector>

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