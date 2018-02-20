# 02/19/2018
# Time  : O(n*lgk)
# Space : O(n)

class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        
        # Standard technique using a head
        #  - maintain a list of k largest elements using a min-heap
        #  - return the top of the heap at the end
        
        import heapq
        min_heap = []
        for x in nums:
            heapq.heappush(min_heap, x)
            if len(min_heap) > k: # maintain min_heap size of k
                heapq.heappop(min_heap)
        return min_heap[0]
