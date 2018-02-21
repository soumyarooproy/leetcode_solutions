# 02/21/2018
# Time  : O(n), n is sqrt(c)
# Space : O(1)
# Notes : Similar to the two-sum

class Solution:
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """

        # Use two-pointer technique
        lb, ub = 0, int(math.sqrt(c))
        while lb <= ub:
            sum = lb*lb + ub*ub
            if sum == c:
                return True
            elif sum < c:
                lb += 1
            else:
                ub -= 1
        
        return False
