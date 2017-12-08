# 66 ms, 12/07/2017
# Time  : O(n^2), considering substring comparison is O(n)
# Space : O(n)
class Solution:
    def wordBreak(self, s, d):
        """
        :type s: str
        :type d: List[str]
        :rtype: bool
        """
        
        """
        Let S[i] indicate whether string s[i:] can be segmented.
        DP equation (n = len(s)) is:
            S[i] = s[i:] starts with w and S[i + ||w||] for all w in d, 0 <= i < n
            S[n] = True
        """
        S = [False] * len(s)
        S.append(True)

        for i in range(len(s) - 1, -1, -1):
            S[i] = any(s.startswith(w, i) and S[i + len(w)] for w in d)

        return S[0]
