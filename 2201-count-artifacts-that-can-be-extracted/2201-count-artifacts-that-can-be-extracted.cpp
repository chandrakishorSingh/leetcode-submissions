class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> grid(n, vector<int>(n));
        
        for (auto& cell: dig)
            grid[cell[0]][cell[1]] = 1;
        
        for (int i = 1; i < n; i++)
            grid[i][0] += grid[i - 1][0];
        
        for (int i = 1; i < n; i++)
            grid[0][i] += grid[0][i - 1];
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1] + grid[i][j];
            }
        }
        
        int result = 0;
        for (auto& artifact: artifacts) {
            int r1 = artifact[0];
            int c1 = artifact[1];
            int r2 = artifact[2];
            int c2 = artifact[3];
            
            if ((r2 - r1 + 1) * (c2 - c1 + 1) == prefixSum(r1, c1, r2, c2, grid))
                result++;
        }
                
        
        return result;
    }
    
    int prefixSum(int r1, int c1, int r2, int c2, vector<vector<int>>& grid) {
        int right = r1 - 1 >= 0 ? grid[r1 - 1][c2]: 0;
        int bottom = c1 - 1 >= 0 ? grid[r2][c1 - 1]: 0;
        int top = (r1 - 1 >= 0) && (c1 - 1 >= 0) ? grid[r1 - 1][c1 - 1]: 0;
        
        return grid[r2][c2] - right - bottom + top;
    }
};

// TC: O(n^2)
// SC: O(n^2)