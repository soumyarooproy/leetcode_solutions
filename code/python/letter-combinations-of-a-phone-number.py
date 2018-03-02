# 03/01/2018
# Time  : O(m**n), n = number of digits and m = number of chars per digit
# Space : O(n)

class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []
        
        num2char = [[],
                    [],
                    ['a', 'b', 'c'],
                    ['d', 'e', 'f'],
                    ['g', 'h', 'i'],
                    ['j', 'k', 'l'],
                    ['m', 'n', 'o'],
                    ['p', 'q', 'r', 's'],
                    ['t', 'u', 'v'],
                    ['w', 'x', 'y', 'z']
                   ]

        list_chars = ['' for _ in digits]
        result = []
        def gen_all_combs(index):
            if index == len(digits):
                result.append(''.join(list_chars))
                return
            for c in num2char[int(digits[index])]:
                list_chars[index] = c
                gen_all_combs(index + 1)
                
        gen_all_combs(0)
        return result
