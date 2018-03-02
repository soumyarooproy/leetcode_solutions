# 03/01/2018
# Time  : O(n)
# Space : O(n)

class Solution:
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        from collections import OrderedDict
        
        d1 = OrderedDict()
        for i, x in enumerate(str.split()):
            if x not in d1:
                d1[x] = []
            d1[x].append(i)

        d2 = OrderedDict()
        for i, x in enumerate(pattern):
            if x not in d2:
                d2[x] = []
            d2[x].append(i)
        
        return len(d1.values()) == len(d2.values()) and all(x == y for x, y in zip(d1.values(), d2.values()))
        
