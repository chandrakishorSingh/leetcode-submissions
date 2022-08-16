class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result(n - 2, vector<int>(n - 2, INT_MIN));
        
        for (int i = 1; i < n - 1; i++)
            for (int j = 1; j < n - 1; j++)
                for (int k = i - 1, rowCount = 0; rowCount < 3; rowCount++, k++)
                    for (int l = j - 1, colCount = 0; colCount < 3; colCount++, l++)
                        result[i - 1][j - 1] = max(result[i - 1][j - 1], grid[k][l]);
        
        return result;
    }
};