class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + matrix[i - 1][j - 1];
        
        int result = 0;
        for (int xi = 1; xi <= m; xi++)
            for (int yi = 1; yi <= n; yi++)
                for (int xj = xi; xj <= m; xj++)
                    for (int yj = yi; yj <= n; yj++)
                        if (matrixSum(prefixSum, xi, yi, xj, yj) == target)
                            result++;
        
        return result;
    }
    
    int matrixSum(vector<vector<int>>& prefixSum, int xi, int yi, int xj, int yj) {
        return prefixSum[xj][yj] - prefixSum[xi - 1][yj] - prefixSum[xj][yi - 1] + prefixSum[xi - 1][yi - 1];
    }
};

// TC: O((m * n)^3)
// SC: O(1)