# Date  : 3/22/2018
# Time  : O(1) on average for get and put
# Space : O(n)
# Notes : Use collections.OrderedDict()

class LRUCache:

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self._map = collections.OrderedDict()
        self._size = capacity

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self._map:
            return -1
        self._map.move_to_end(key)
        return self._map[key]

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        self._map[key] = value
        self._map.move_to_end(key)
        if len(self._map) > self._size:
            self._map.popitem(last=False)

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
