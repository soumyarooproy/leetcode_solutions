# 02/15/2018
# Time  : O(2**n)
# Space : O(2**n)
class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def gen_powerset(nums, index, depth=0):
            if index >= 0:
                gen_powerset(nums, index - 1, depth + 1);
                res.extend([s + [nums[index]] for s in res])

        """
        Use the recursive relation:
          PS(s) = PS(s - {x}) U {Y U {x} for all Y in P(S - {x})}, x in S
        Example:
          PS({1, 2, 3}) = PS({1, 2} U {Y U {3} for all Y in PS({1, 2})}
                        = {{}, {1}, {2}, {1, 2}} U {{3}, {1, 3}, {2, 3}, {1, 2, 3}}
        """

        res = [[]]
        gen_powerset(nums, len(nums) - 1)
        return res
