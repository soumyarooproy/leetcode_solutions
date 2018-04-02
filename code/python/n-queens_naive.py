# Date  : 04/02/2018
# Time  : O(n!)
# Space : O(n**3); n**2 board is used in each stack frame, which is n deep
# Notes : Naive implementation

class Solution:
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        res = []
        def solve_n_queens_helper(row, pos_queens, board, depth=0):
            #print(' '*depth, 'row =', row, 'board =', board, 'pos_queens =', pos_queens)
            if row == n:
                #print(' '*depth, 'Yass - sucess!')
                res.append([''.join('Q' if (r, c) in pos_queens else '.' for c in range(n)) for r in range(n) ])
                return
            for col in range(n):
                if board[row][col] == 1:
                    continue
                # Make the queen placement
                pos_queens.add((row, col))
                board_copy = copy.deepcopy(board)
                # Mark all the cells covered by the queen placement
                # Horizontal and vertical
                for i in range(n):
                    board_copy[i][col] = 1
                    board_copy[row][i] = 1
                # Diagonals
                i, j = row, col
                while i >= 0 and j >= 0:
                    board_copy[i][j] = 1
                    i, j = i - 1, j - 1
                i, j = row, col
                while i < n and j >= 0:
                    board_copy[i][j] = 1
                    i, j = i + 1, j - 1
                i, j = row, col
                while i >= 0 and j < n:
                    board_copy[i][j] = 1
                    i, j = i - 1, j + 1
                i, j = row, col
                while i < n and j < n:
                    board_copy[i][j] = 1
                    i, j = i + 1, j + 1
                solve_n_queens_helper(row + 1, pos_queens, board_copy, depth + 1)
                # Undo the queen placement
                pos_queens.discard((row, col))
            else:
                pass
                #print(' '*depth, 'Bummer - fail!')

        solve_n_queens_helper(0, set(), [[0] * n for _ in range(n)])
        return res
