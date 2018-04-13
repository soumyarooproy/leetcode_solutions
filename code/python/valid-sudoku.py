# Date  : 04/13/2018
# Time  : O(n**2), n = 9
# Space : O(n**2), 3*n**2 to be precise

class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """

        row_set = [set() for _ in range(9)]
        col_set = [set() for _ in range(9)]
        box_set = [set() for _ in range(9)]
        
        for i, row in enumerate(board):
            for j, num in enumerate(row):
                if num != '.':
                    index_box = 3 * (i // 3) + j // 3;
                    if num in row_set[i] or num in col_set[j] or num in box_set[index_box]:
                        return False
                    row_set[i].add(num)
                    col_set[j].add(num)
                    box_set[index_box].add(num)
        
        return True
