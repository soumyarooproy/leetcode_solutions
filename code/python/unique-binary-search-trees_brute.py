# TLE, 12/09/2017
# Time  : O(c**n)?
# Space : O(1)
class Solution:
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        """
        To obtain unique BSTs, consider values 1..n in ascending order and
        anchor the root of the BST at each value. For e.g., for n = 3,
        - BST(1) can have no left subtree and a right subtree with values 2 and 3
        - BST(2) can have a left subtree with value 1 and a right subtree with value 3
        - BST(3) can have a right subtree with values 2 and 3 and no left subtree
        
        Recursive relation:
            num_bsts(i) = _sum{nums_bsts(j - 1) * num_bsts(n - j)} for all 1 <= j <= n
        """
        if n < 2:
            return 1
        count = 0
        for r in range(n):
            count += self.numTrees(r) * self.numTrees(n - r - 1)
        return count
