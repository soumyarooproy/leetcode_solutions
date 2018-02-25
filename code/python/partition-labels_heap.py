# 02/24/2018
# Time  : O(n + m*logm), where m is 26 ('a'-'z')
# Space : O(n + m)
class Solution:
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        
        # Convert chars into an interval of indices of their appearance in S
        # "abba" -> a: (0, 3), b: (1, 2)
        from collections import OrderedDict
        intervals = OrderedDict()
        for i, c in enumerate(S):
            if c in intervals:
                intervals[c][1] = i
            else:
                intervals[c] = [i, i]
        
        # Now determine the disjoint sections in the set of intervals sorted
        # by start times:
        # |--------|
        #   |---|
        #           |------|
        #             |------|
        # <-part1->|<-part2->
        
        # Use a min-heap to track the current intervals
        import heapq
        partitions = []
        min_heap = []
        last_partition_index = 0
        for start, stop in intervals.values():
            
            # Pop out all the intervals from the heap whose stop times are
            # before the current start time
            while min_heap and min_heap[0] < start:
                heapq.heappop(min_heap)
            
            # Heap empty implies a partition
            if not min_heap and start:
                partitions.append(start - last_partition_index)
                last_partition_index = start
            
            # Push the current interval into the heap
            heapq.heappush(min_heap, stop)
        
        return partitions + [len(S) - last_partition_index] # append the last partition
