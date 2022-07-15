class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n));
        int result = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                result = max(result, dfs(i, j, grid, visited));
            
        return result;
    }
    
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (row < 0 || row >= m || col < 0 || col >= n || visited[row][col] || grid[row][col] == 0)
            return 0;
        
        visited[row][col] = 1;
        
        int result = 1;
        
        result += dfs(row - 1, col, grid, visited);
        result += dfs(row, col + 1, grid, visited);
        result += dfs(row + 1, col, grid, visited);
        result += dfs(row, col - 1, grid, visited);
        
        return result;
    }
};

// TC: O(m * n)
// SC: O(m * n)