# 58 ms, 02/05/2018
# Time  : O(N), N is O(lg K)
# Space : O(N) below, can made O(1)
class Solution(object):
    def kthGrammar(self, N, K):
        return bin(K - 1).count('1') % 2
