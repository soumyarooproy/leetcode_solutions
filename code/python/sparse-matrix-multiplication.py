# Date  : 03/20/2018
# Time  : O(m'*n'*o'), matrix sizes m-by-n (m'*n' non-zero values) and n-by-o (n'*o' non-zero values)
# Space : O(m'*n' + n'*o')
# Notes : Sparse matrix representation (http://www.cs.cmu.edu/~scandal/cacm/node9.html)

class Solution:
    def multiply(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: List[List[int]]
        """

        # Represent a matrix as a sparse matrix; use hash table to omit all-zero rows
        def sparse_matrix(A):
            S_A = collections.defaultdict(list)
            for i, row in enumerate(A):
                for j, x in enumerate(row):
                    if x:
                        S_A[i].append((j, x))
            return S_A

        S_A, S_B = sparse_matrix(A), sparse_matrix(B)
        m, n, o = len(A), len(A[0]), len(B[0])
        res = [[0] * o for _ in range(m)]

        for i, row_A in S_A.items():
            for j, x in row_A:
                if j in S_B:
                    for k, y in S_B[j]:
                        res[i][k] += x * y

        return res
