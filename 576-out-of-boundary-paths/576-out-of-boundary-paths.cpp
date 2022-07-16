class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.resize(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        
        return _findPaths(m, n, maxMove, startRow, startColumn);
    }
    
    int _findPaths(int m, int n, int remainingMoveCount, int currentRow, int currentColumn) {
        if (remainingMoveCount < 0)
            return 0;
        
        if (currentRow < 0 || currentRow >= m || currentColumn < 0 || currentColumn >= n)
            return 1;
        
        if (dp[currentRow][currentColumn][remainingMoveCount] != -1)
            return dp[currentRow][currentColumn][remainingMoveCount];
        
        int64_t result = 0;
        result = ((result % mod) + (_findPaths(m, n, remainingMoveCount - 1, currentRow - 1, currentColumn) % mod)) % mod;
        result = ((result % mod) + (_findPaths(m, n, remainingMoveCount - 1, currentRow, currentColumn + 1) % mod)) % mod;
        result = ((result % mod) + (_findPaths(m, n, remainingMoveCount - 1, currentRow + 1, currentColumn) % mod)) % mod;
        result = ((result % mod) + (_findPaths(m, n, remainingMoveCount - 1, currentRow, currentColumn - 1) % mod)) % mod;
        
        dp[currentRow][currentColumn][remainingMoveCount] = result;
        
        return result;
    }
};

// TC: O(4^maxMove)
// SC: O(maxMove)