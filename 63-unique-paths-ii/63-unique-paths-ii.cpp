class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1)
            return 0;
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int64_t>> store(m, vector<int64_t>(n));
        store[0][0] = 1 - obstacleGrid[0][0];
        
        for (int i = 1; i < m; i++)
            store[i][0] = obstacleGrid[i][0] == 1 ? 0: store[i - 1][0];
        for (int i = 1; i < n; i++)
            store[0][i] = obstacleGrid[0][i] == 1 ? 0: store[0][i - 1];
        
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                store[i][j] = obstacleGrid[i][j] == 1 ? 0: store[i - 1][j] + store[i][j - 1];
        
        return store[m - 1][n - 1];
    }
};

// TC: O(2^(m + n))
// SC: O(m + n)