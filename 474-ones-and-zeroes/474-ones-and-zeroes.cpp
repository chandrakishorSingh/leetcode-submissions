class Solution {
public:
    typedef vector<vector<vector<int>>> vector3d;
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        
        vector<vector<int>> bitCount(2, vector<int>(size));
        for (int i = 0; i < size; i++) {
            bitCount[0][i] = count(strs[i].begin(), strs[i].end(), '0');
            bitCount[1][i] = strs[i].size() - bitCount[0][i];
        }
        
        vector3d dp(size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int i = 1; i <= size; i++) {
            int zeroCount = bitCount[0][i - 1];
            int oneCount = bitCount[1][i - 1];
            
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    if (j == 0 && k == 0)
                        continue;
                    
                    int option1 = dp[i - 1][j][k];
                    int option2 = (zeroCount <= j && oneCount <= k) ? 1 + dp[i - 1][j - zeroCount][k - oneCount]: 0;
                    
                    dp[i][j][k] = max(option1, option2);
                }
            }
        }
        
        return dp[size][m][n];
    }
};

// TC: O(size * m * n)
// SC: O(size * m * n)