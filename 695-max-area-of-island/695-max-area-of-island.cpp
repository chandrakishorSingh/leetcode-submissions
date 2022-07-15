class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int result = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                result = max(result, dfs(i, j, grid));
        
        return result;
    }
    
    int dfs(int row, int col, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == -1 || grid[row][col] == 0)
            return 0;
        
        grid[row][col] = -1;
        
        int result = 1;
        
        result += dfs(row - 1, col, grid);
        result += dfs(row, col + 1, grid);
        result += dfs(row + 1, col, grid);
        result += dfs(row, col - 1, grid);
        
        return result;
    }
};