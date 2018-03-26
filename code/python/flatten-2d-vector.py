# Date  : 03/25/2018
# Time  : O(1) on average for both hasNext() and next()
# Space : O(1) 
# Notes : hasNext() needs to be idempotent, i.e., it should not advance the iterator;
#         also the functionality of next() should not depend on that of hasNext()
#         it should be able to be called successively without intervening calls
#         to hasNext()

class Vector2D(object):

    def __init__(self, vec2d):
        """
        Initialize your data structure here.
        :type vec2d: List[List[int]]
        """
        self._vec2d = vec2d
        self._row, self._col = 0, -1
        self._advance()

    def _advance(self):
        self._col += 1
        while self._row < len(self._vec2d) and self._col == len(self._vec2d[self._row]):
            self._row, self._col = self._row + 1, 0
            
    def next(self):
        """
        :rtype: int
        """
        val = self._vec2d[self._row][self._col]
        self._advance()
        return val

    def hasNext(self):
        """
        :rtype: bool
        """
        return self._row < len(self._vec2d)

# Your Vector2D object will be instantiated and called as such:
# i, v = Vector2D(vec2d), []
# while i.hasNext(): v.append(i.next())
