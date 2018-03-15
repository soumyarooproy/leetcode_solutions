# 03/15/2018
# Time  : O(n) for each function, n = size of the word to be inserted
# Space : O(n) worst case for insert(), O(1) for the rest 

class Trie:
    END = "END"
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._root = {}
        
    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        node = self._root
        for c in word:
            if c not in node:
                node[c] = {}
            node = node[c]
        node[Trie.END] = True

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        node = self._root
        for c in word:
            if not c in node:
                return False
            node = node[c]
        return Trie.END in node

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        node = self._root
        for c in prefix:
            if not c in node:
                return False
            node = node[c]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
