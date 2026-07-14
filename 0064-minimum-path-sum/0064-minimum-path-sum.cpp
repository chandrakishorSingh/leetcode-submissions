class Solution {
private:
    int solve(vector<vector<int>>& store, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i != 0 && j != 0) {
                    store[i][j] = grid[i][j] + min(store[i - 1][j], store[i][j - 1]);
                } else if (i == 0 && j != 0) {
                    store[i][j] = grid[i][j] + store[i][j - 1];
                } else if (i != 0 && j == 0) {
                    store[i][j] = grid[i][j] + store[i - 1][j];
                } else {
                    store[i][j] = grid[i][j];
                }
            }
        }
        
        return store[m - 1][n - 1];
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int result = INT_MAX;
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> store(m, vector<int>(n));
        
        return solve(store, grid);
    }
};

// TC: O(m * n)
// SC: O(m * n)