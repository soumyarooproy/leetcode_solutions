# Date  : 03/18/2018
# Time  : O(n)
# Space : O(n)
# Notes : This implementation took ~500ms on leetcode; fastest solution on there <100 ms.

class Solution:
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        word_dict = set(wordList)        
        if not endWord in word_dict:
            return 0

        LETTERS = 'abcdefghijklmnopqrstuvwxyz'
        q, num_trans = [beginWord], 1
        while q:
            new_q = []
            for w in q:
                for i in range(len(w)):
                    for c in LETTERS:
                        if w[i] == c:
                            continue
                        new_word = w[0:i] + c + w[i+1:]
                        if new_word in word_dict:
                            if new_word == endWord:
                                return num_trans + 1
                            new_q.append(new_word)
                            word_dict.discard(new_word)
            q = new_q
            num_trans += 1
        return 0
