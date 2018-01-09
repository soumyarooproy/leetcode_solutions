# 01/08/2017, 146 ms
# Time  : O(m), m being the size of the input, i.e., log(n)
# Space : O(m)
# Notes : Refer to happy-number.py for description
class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        seen = set()
        def is_happy_recursive(n):
            if n in seen:
                return n == 1
            seen.add(n)
            return is_happy_recursive(sum(int(c)**2 for c in str(n)))
        return is_happy_recursive(n)
