class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        
        # Ensure that nums1 is NOT the longer of the two arrays
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        
        m, n = len(nums1), len(nums2)
        
        # Determine if the total number of elements is even
        even = not bool((m + n) & 0b1)
        
        # Compute the mid point, k, such that
        # median = the (k-1)th item, if total number of elements is odd
        #        = the avg. of (k-1)th and k-th items, otherwise
        half = (m + n + 1) // 2
        
        # Compute median recursively using binary search
        def find_median_recur(low1, high1):
            index1 = (low1 + high1) // 2
            index2 = half - index1
            
            # Go right to find the partition
            if index1 < m and nums1[index1] < nums2[index2 - 1]:
                return find_median_recur(index1 + 1, high1)
            
            # Go left to find the partition
            if index1 > 0 and nums2[index2] < nums1[index1 - 1]:
                return find_median_recur(low1, index1 - 1)
            
            # Partitions for median found!
            max_left = max(nums1[index1 - 1] if index1 > 0 else float('-inf'),
                           nums2[index2 - 1] if index2 > 0 else float('-inf'))
            
            if not even:
                return max_left
            
            min_right = min(nums1[index1] if index1 < m else float('inf'),
                            nums2[index2] if index2 < n else float('inf'))
            
            return (max_left + min_right) / 2
                
        return find_median_recur(0, m)
