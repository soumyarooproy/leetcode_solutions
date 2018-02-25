# 02/24/2018
# Time  : O(n)
# Space : O(n)
# Notes: Solution on leetcode (https://leetcode.com/problems/partition-labels/solution/)

class Solution(object):
    def partitionLabels(self, S):
        last = {c: i for i, c in enumerate(S)}
        
        # Two pointer technique
        begin = end = 0
        ans = []
        for i, c in enumerate(S):
            end = max(end, last[c])
            if i == end:
                ans.append(i - begin + 1)
                begin = i + 1
            
        return ans
