class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        mat = [[0] * n for _ in range(n)]
        for r1, c1, r2, c2 in queries:
            mat[r1][c1] += 1
            if r2 + 1 < n: mat[r2 + 1][c1] -= 1
            if c2 + 1 < n: mat[r1][c2 + 1] -= 1
            if r2 + 1 < n and c2 + 1 < n: mat[r2 + 1][c2 + 1] += 1
        for i in range(1, n):
            for j in range(n):
                mat[i][j] += mat[i - 1][j]
        for i in range(n):
            for j in range(1, n):
                mat[i][j] += mat[i][j - 1]
        return mat