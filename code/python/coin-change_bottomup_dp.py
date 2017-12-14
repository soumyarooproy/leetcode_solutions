"""
TLE, 12/13/2017
Time  : O(n*m)
Space : O(n)
"""
class Solution:
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        coins.sort()
        M = [(amount + 1) for _ in range(amount + 1)]
        M[0] = 0

        for c in coins:
            for i in range(c, amount + 1):
                M[i] = min(1 + M[i - c], M[i])

        return -1 if M[-1] == (amount + 1) else M[-1]
