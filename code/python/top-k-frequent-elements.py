# 02/19/2018
# Time  : O(n*lgk)
# Space : O(m + k), m is the number of distinct elems in nums

class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        import collections
        freq = collections.defaultdict(int)
        for x in nums:
            freq[x] += 1
        
        min_heap = []
        for key, count in freq.items():
            if len(min_heap) < k:
                heapq.heappush(min_heap, (count, key))
            else:
                heapq.heappushpop(min_heap, (count, key))
        
        return [x[1] for x in min_heap]
