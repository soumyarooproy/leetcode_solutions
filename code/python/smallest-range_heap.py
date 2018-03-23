# Date  : 3/22
# Time  : O(n * lg(k))
# Space : O(k)
# Notes : This approach borrows ideas from (1) merging k sorted arrays and (2) finding the min diff
#         between 2 sorted arrays

class Solution:
    def smallestRange(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: List[int]
        """
        # Construct a min_heap with the min elements in each of the k lists
        min_heap = [(l[0], list_index, 0) for list_index, l in enumerate(nums)]      # O(k)
        heapq.heapify(min_heap)                                                      # O(k)
        
        range_max = max(min_heap)[0]                                                 # O(k)
        range_smallest = float('inf'), None                                          # O(1)

        # Iterate till a list is exhausted
        while True:                                                                  # O(n - k)
            range_min, list_index, item_index = heapq.heappop(min_heap)              # O(lg(k))
            # Compute the range
            range_smallest = min(range_smallest, (range_max - range_min, range_min)) # O(1)
            if item_index == len(nums[list_index]):                                  # O(1)
                break
            # Determine the next key
            next_key = nums[list_index][item_index]                                  # O(1)
            # Update range_max with the next key
            range_max = max(next_key, range_max)                                     # O(1)
            heapq.heappush(min_heap, (next_key, list_index, item_index + 1))         # O(lg(k))
        
        return [range_smallest[1], range_smallest[1] + range_smallest[0]]            # O(1)
