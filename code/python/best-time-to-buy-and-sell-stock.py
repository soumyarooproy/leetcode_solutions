# 69 ms, 12/06/2017
# Time  : O(n)
# Space : O(1)
class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0
        max_profit, min_price = 0, prices[0]
        for x in prices[1:]:
            min_price = min(min_price, x)
            max_profit = max(max_profit, x - min_price)

        return max_profit
