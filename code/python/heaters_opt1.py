# 02/28/2018
# Time  : O(max(m, n)*log(min(m, n))) // Sort the shorter array
# Space : O(1)

class Solution:
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        import bisect
        heaters.sort()
        radius = float('-inf')
        for i, house in enumerate(houses):
            lb = bisect.bisect_left(heaters, house)
            if 0 < lb < len(heaters):
                m = min(abs(house - heaters[lb]), abs(house - heaters[lb - 1]))
            elif not lb:
                m = abs(house - heaters[lb])
            else:
                m = abs(house - heaters[lb - 1])            
            radius = max(radius, m)
        return radius
