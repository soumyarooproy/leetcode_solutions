# 02/21/2018
# Time  : O(n), n = lg(x)
# Space : O(1)

class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        y, neg, x = 0, x < 0, abs(x)
        while x:
            y = y*10 + x%10
            x //= 10
        y = -y if neg else y
        return y if -2147483648 <= y < 2147483648 else 0
