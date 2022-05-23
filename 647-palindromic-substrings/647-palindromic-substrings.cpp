class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        int result = s.size();
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            
            for (int j = i - 1; j >= 0; j--) {
                if (s[j] == s[i]) {
                    if (j + 1 <= i - 1 && dp[j + 1][i - 1] == 0)
                        continue;
                    
                    dp[j][i] = 1;
                    result++;
                }
            }
        }
        
        return result;
    }
};

// TC: O(n^2)
// SC: O(1)