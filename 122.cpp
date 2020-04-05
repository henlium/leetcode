#include "common.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;
        int buy = prices[0];
        int profit = 0;
        int sum = 0;
        for (int i = 1; i < n; ++i)
        {
            int price = prices[i];
            if (price < prices[i - 1])
            {
                sum += profit;
                profit = 0;
                buy = price;
                continue;
            }
            if (price < buy)
            {
                buy = price;
                continue;
            }
            if ((price - buy) > profit)
            {
                profit = price - buy;
                continue;
            }
        }
        sum += profit;
        return sum;
    }
};