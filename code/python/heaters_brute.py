# 02/28/2018
# Time  : O(n*m)
# Space : O(1)

class Solution:
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        import functools
        return max(functools.reduce(min, (abs(house - heater) for heater in heaters)) for house in houses)
