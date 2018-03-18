# 03/17/2018
# Time  : O(n)
# Space : O(n); can easily be O(1)

class Solution:
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        count, gaps = 1, []
        for f in flowerbed:
            if not f:
                count += 1
            elif count:
                gaps.append(count)
                count = 0
        gaps.append(count + 1)
        
        return n <= sum((x - 1) // 2 for x in gaps)
