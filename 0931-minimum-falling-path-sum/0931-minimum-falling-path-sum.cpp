class Solution {    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> store(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    store[i][j] = matrix[i][j];
                    continue;
                }
                
                if (j == 0 && n != 1) {
                    store[i][j] = matrix[i][j] + min(store[i - 1][j], store[i - 1][j + 1]);
                } else if (j == n - 1 && n != 1) {
                    store[i][j] = matrix[i][j] + min(store[i - 1][j], store[i - 1][j - 1]);
                } else {
                    store[i][j] = matrix[i][j] + min(min(store[i - 1][j - 1], store[i - 1][j]), store[i - 1][j + 1]);
                }
            }
        }
        
        return *min_element(store[n - 1].begin(), store[n - 1].end());
    }
};

// TC: O(n^2)
// SC: O(n^2)