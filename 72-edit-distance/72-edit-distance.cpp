class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        
        return _minDistance(n1, n2, word1, word2, dp);
    }
    
    int _minDistance(int n1, int n2, string& word1, string& word2, vector<vector<int>>& dp) {
        if (n1 == 0 || n2 == 0)
            return n1 + n2;
        
        if (dp[n1][n2] != -1)
            return dp[n1][n2];
        
        int result = -1;
        if (word1[n1 - 1] == word2[n2 - 1]) {
            result = _minDistance(n1 - 1, n2 - 1, word1, word2, dp);
        } else {
            result = min({
                1 + _minDistance(n1, n2 - 1, word1, word2, dp),
                1 + _minDistance(n1 - 1, n2, word1, word2, dp),
                1 + _minDistance(n1 - 1, n2 - 1, word1, word2, dp),
            });
        }
        
        dp[n1][n2] = result;
        
        return dp[n1][n2];
    }
};