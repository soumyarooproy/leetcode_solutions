# 03/02/2018
# Time  : O(1) for hit(), O(n) worst case for getHits(), n = 300
# Space : O(n)
# Notes : This solution assumes that hit() is called at most once for one timestamp

class HitCounter:
    WINDOW_SIZE = 300

    def __init__(self):
        """
        Initialize your data structure here.
        """
        import collections
        self._q = collections.deque()

    def hit(self, timestamp):
        """
        Record a hit.
        @param timestamp - The current timestamp (in seconds granularity).
        :type timestamp: int
        :rtype: void
        """
        self._q.append(timestamp)
        while self._q[0] < timestamp - self.WINDOW_SIZE:
            self._q.popleft()

    def getHits(self, timestamp):
        """
        Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity).
        :type timestamp: int
        :rtype: int
        """
        while self._q and self._q[0] <= timestamp - self.WINDOW_SIZE:
            self._q.popleft()
        return len(self._q)


# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)
