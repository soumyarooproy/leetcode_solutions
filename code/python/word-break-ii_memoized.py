# 03/01/2018
# Time  : O(??)
# Space : O(n)

class Solution:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """

        from functools import lru_cache
        
        # Memoized function to compute the number of dictionary word matches at position index of s
        @lru_cache(maxsize=None)
        def gen_matches(index):
            if index == len(s):
                return ['']
            return [word for word in wordDict if s.startswith(word, index) and gen_matches(index + len(word))]
        
        # This function constructs all the sentences by recursively generating all combinations of matched words
        sentences, word_list = [], []
        def gen_sentences_recur(index):
            if index == len(s):
                sentences.append(' '.join(word_list))
                return
            for word in gen_matches(index):
                word_list.append(word)
                gen_sentences_recur(index + len(word))
                word_list.pop()

        gen_sentences_recur(0)
        return sentences
