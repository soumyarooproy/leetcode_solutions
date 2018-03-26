# Date  : 03/25/2018
# Time  : O(1)
# Space : O(1)
# Notes : For Leetcode, precompute self._lookup_reverse (of len 256)

class Solution:
    REV = [0b0000, 0b1000, 0b0100, 0b1100,
           0b0010, 0b1010, 0b0110, 0b1110,
           0b0001, 0b1001, 0b0101, 0b1101,
           0b0011, 0b1011, 0b0111, 0b1111]
    
    def __init__(self):
        self._lookup_reverse = [self._reverse(i) for i in range(256)]

    def _reverse(self, x):
        return self.REV[x & 0xf] << 4 | self.REV[(x >> 4) & 0xf]
    
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        return ((self._lookup_reverse[n & 0xff] << 24)
                | (self._lookup_reverse[(n >> 8) & 0xff] << 16)
                | (self._lookup_reverse[(n >> 16) & 0xff] << 8)
                | (self._lookup_reverse[(n >> 24) & 0xff]))
