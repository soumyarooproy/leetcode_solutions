// 6 ns, 09/14/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        // Buy at local minimas and sell at subsequently next local maximas
        int max_profit = 0;
        for (int i = 0, n = prices.size(); i < n; ++i) {
            while ((i + 1) < n && prices[i + 1] <= prices[i]) ++i;
            if (i == n - 1)
                break;
            int buy = prices[i];
            while ((i + 1) < n && prices[i + 1] >= prices[i]) ++i;
            int sell = prices[i];
            max_profit += sell - buy;
        }
        return max_profit;
    }
};
