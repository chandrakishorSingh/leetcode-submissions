class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.resize(m + 1, vector<vector<int>>(n + 1, vector<int>(maxMove + 1, -1)));
        
        // dp[startRow][startColumn][0] = 1;
        
//         int64_t result = 0;
//         for (int i = 0; i < m; i++)
//             for (int j = 0; j < n; j++)
//                 if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
//                     result = ((result % mod) + (_findPaths(m, n, maxMove, i, j) % mod)) % mod;
        
        return _findPaths(m, n, maxMove, startRow, startColumn);
    }
    
    int _findPaths(int m, int n, int remainingMoveCount, int currentRow, int currentColumn) {
        if(remainingMoveCount < 0) return 0;
        if (currentRow < 0 || currentRow >= m || currentColumn < 0 || currentColumn >= n)
            return 1;
        
        if (dp[currentRow][currentColumn][remainingMoveCount] != -1)
            return dp[currentRow][currentColumn][remainingMoveCount];
        
        int64_t result = 0;
        if (remainingMoveCount > 0) {
            result = ((result % mod) + (_findPaths(m, n, remainingMoveCount - 1, currentRow - 1, currentColumn) % mod)) % mod;
            result = ((result % mod) + (_findPaths(m, n, remainingMoveCount - 1, currentRow, currentColumn + 1) % mod)) % mod;
            result = ((result % mod) + (_findPaths(m, n, remainingMoveCount - 1, currentRow + 1, currentColumn) % mod)) % mod;
            result = ((result % mod) + (_findPaths(m, n, remainingMoveCount - 1, currentRow, currentColumn - 1) % mod)) % mod;
        }
        
        dp[currentRow][currentColumn][remainingMoveCount] = result;
        
        return result;
    }
};

// TC: O(4^maxMove)
// SC: O(maxMove)