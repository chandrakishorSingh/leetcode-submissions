class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> store(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                store[i][j] = matrix[i][j] == '1' ? 1 : 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // cout << store[i][j] << " ";
            }
            // cout << endl;
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int minSquareLength = min(store[i - 1][j], store[i][j - 1]);
                
                if (matrix[i][j] == '1' && minSquareLength != 0) {
                    if (matrix[i - minSquareLength][j - minSquareLength] == '1') {
                        store[i][j] = 1 + minSquareLength;
                    } else {
                        store[i][j] = minSquareLength;
                    }
                    // cout << "after adding " << store[i][j] << " ";
                }
                
                // cout << "(" << i << ", " << j << ") = "  << store[i][j] << " and minSquareLength = " << minSquareLength << endl;
            }
            
            // cout << endl;
        }
        
        int result = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                result = max(result, store[i][j]);
        
        return result * result;
    }
};