# Date  : 04/02/2018
# Time  : O(n**2)
# Space : O(n)
# Notes : Solution in EPI

# Definition for a point.
# class Point:
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

import fractions
class Solution:
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
 
        Point.__eq__  = lambda a, b : a.x == b.x and a.y == b.y
        
        max_points = 0
        for i, p1 in enumerate(points):
            slopes = collections.defaultdict(int)
            dups = 1
            for p2 in points[i + 1:]:
                if p1 == p2:       # Duplicate point
                    dups += 1
                elif p1.x == p2.x: # Vertical line
                    slopes[(1, 0)] += 1
                else:              # non-vertical line - compute slope
                    x_del, y_del = p2.x - p1.x, p2.y - p1.y
                    gcd = fractions.gcd(x_del, y_del)
                    slopes[(y_del // gcd, x_del // gcd)] += 1
            max_points = max(max_points, dups + max(slopes.values(), default=0))

        return max_points
