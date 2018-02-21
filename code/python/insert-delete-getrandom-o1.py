# 02/20/2018
# Time  : O(1) average
# Space : O(n)
class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.list_keys = [] # store keys for random lookup
        self.map_keys = {}  # store key->array index map

    def insert(self, val):
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        if val in self.map_keys:
            return False
        # Append key to array and make a key->array index entry in the map
        self.list_keys.append(val)
        self.map_keys[val] = len(self.list_keys) - 1
        return True

    def remove(self, val):
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        :type val: int
        :rtype: bool
        """
        # Deletion from the hash table is simple; deletion from the array is tricky
        # because it creates a hole in the array
        # Instead of performing compaction, just copy the last array element over
        # to the hole and reduce the array size by 1
        # Also update the hash table for the moved key to point to the correct
        # array index
        if val in self.map_keys:
            delete_index = self.map_keys[val]
            self.map_keys[self.list_keys[-1]] = delete_index
            self.list_keys[delete_index] = self.list_keys[-1]
            del self.map_keys[val]
            del self.list_keys[-1]
            return True
        return False

    def getRandom(self):
        """
        Get a random element from the set.
        :rtype: int
        """
        return random.choice(self.list_keys)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
