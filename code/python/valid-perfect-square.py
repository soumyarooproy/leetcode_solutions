# 02/21/2018
# Time  : O(lg(n))
# Space : O(1)
# Notes : Use binary search

class Solution:
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        lb, ub = 0, num
        
        while lb <= ub:
            mid = lb + (ub - lb)//2
            square = mid**2
            if square == num:
                return True
            elif square < num:
                lb = mid + 1
            else:
                ub = mid - 1
        
        return False
