class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> store(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                store[i][j] = matrix[i][j] == '1' ? 1 : 0;
        
        int largestSquareLength = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0' || i == 0 || j == 0) {
                    largestSquareLength = max(largestSquareLength, store[i][j]);
                    continue;
                }
                
                int minSquareLength = min(store[i - 1][j], store[i][j - 1]);
                store[i][j] = minSquareLength + (matrix[i - minSquareLength][j - minSquareLength] == '1' ? 1 : 0);
                
                largestSquareLength = max(largestSquareLength, store[i][j]);
            }
        }
        
        return largestSquareLength * largestSquareLength;
    }
};

// TC: O(m * n)
// SC: O(m * n)