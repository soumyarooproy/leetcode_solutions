# 01/12/2018, 61 ms
# Time  : O(n)
# Space : O(n)
class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        # Convert to integer, increment, and convert back to int list
        num = int(''.join(str(x) for x in digits))
        return [int(c) for c in str(num + 1)]
