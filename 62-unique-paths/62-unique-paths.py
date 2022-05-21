class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        def factorial(n):
            if n <= 1:
                return 1
            
            return n * factorial(n - 1)
        
        return factorial(m + n - 2) // (factorial(m - 1) * factorial(n - 1))