# 03/01/2018
# Time  : O(??)
# Space : O(n)
# Notes : TLE

class Solution:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """

        sentences, word_list = [], []
        # Generate all the sentences by recursively generating all combinations of matched words
        def gen_sentences_recur(index):
            if index == len(s):
                sentences.append(' '.join(word_list))
                return
            for word in wordDict:
                if s.startswith(word, index):
                    word_list.append(word)
                    gen_sentences_recur(index + len(word))
                    word_list.pop()
        
        gen_sentences_recur(0)
        return sentences        
