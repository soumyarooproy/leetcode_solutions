# Date  : 3/22
# Time  : O(1) on average for get() and put()
# Space : O(n)
# Notes : Optimized version uses OrderedDict; optimize this by implementing move_to_end()
#         instead of removing a node and adding a new node with the same (or a different) key

class LRUCache:
    class DoublyLinkedList:
        class ListNode:
            def __init__(self, data=None, next_node=None, prev_node=None):
                self.data = data
                self.next = next_node
                self.prev = prev_node
            def __str__(self):
                return '{}, {}, {}'.format(self.data, hex(id(self.next)), hex(id(self.prev)))

        def __init__(self):
            # Implemented as a circular list with a sentinel node
            # Head is sentinel.next and tail is sentinel.prev
            self._sentinel = self.ListNode()
            self._sentinel.next = self._sentinel
            self._sentinel.prev = self._sentinel

        def __str__(self):
            l = [str(self._sentinel)]
            node = self._sentinel.next
            while not node is self._sentinel:
                l[len(l):], node = [str(node)], node.next
            return str(l)
                  
        def append(self, data):
            node = self.ListNode(data)
            tail = self._sentinel.prev
            # 4 ptr changes
            node.prev = tail
            node.next = tail.next
            tail.next.prev = node
            tail.next = node
            return self._sentinel.prev

        def pop(self, node):
            if node is self._sentinel:
                raise Exception('Empty list')
            node.prev.next = node.next
            node.next.prev = node.prev
            node.prev = node.next = None
            return node.data

        def pop_front(self):
            return self.pop(self._sentinel.next)

        def pop_back(self):
            return self.pop(self._sentinel.prev)
        
    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self._lru_list = self.DoublyLinkedList()
        self._map = {}
        self._size = capacity

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self._map:
            return -1
        _, value = self._lru_list.pop(self._map[key])
        self._map[key] = self._lru_list.append((key, value))
        return value

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if key in self._map:
            self._lru_list.pop(self._map[key])
        elif len(self._map) == self._size:
            del self._map[self._lru_list.pop_front()[0]]
        self._map[key] = self._lru_list.append((key, value))
            

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
