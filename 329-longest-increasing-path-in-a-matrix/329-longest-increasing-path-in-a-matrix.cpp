class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        int result = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                result = max(result, dfs(i, j, matrix, dp));
        
        return result;
    }
    
    int dfs(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[row][col] != -1)
            return dp[row][col];
        
        vector<int> dx = {0, -1, 0, 1};
        vector<int> dy = {1, 0, -1, 0};
        int m = matrix.size();
        int n = matrix[0].size();
        int pathLength = 1;
        for (int i = 0; i < dx.size(); i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            
            if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n)
                continue;
            
            if (matrix[newRow][newCol] > matrix[row][col])
                pathLength = max(pathLength, 1 + dfs(newRow, newCol, matrix, dp));
        }
        
        dp[row][col] = pathLength;
        return dp[row][col];
    }
};

// TC: O(m * n)
// SC: O(m * n)