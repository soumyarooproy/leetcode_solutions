# 01/12/2018, 63 ms
# Time  : O(n)
# Space : O(1)
class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        carry = 1
        for i, d in reversed(list(enumerate(digits))):
            if not carry:
                break
            if d == 9:
                digits[i], carry = 0, 1
            else:
                digits[i], carry = d + 1, 0
        return [1] + digits if carry else digits
