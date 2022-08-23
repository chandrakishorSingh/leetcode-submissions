class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int infinity = 1e4 + 1;
        
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        
        for (int i = 1; i <= amount; i++)
            dp[0][i] = infinity;
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= amount; j++)
                dp[i][j] = min(j >= coins[i - 1] ? 1 + dp[i][j - coins[i - 1]] : dp[i - 1][j], dp[i - 1][j]);
        
        return dp[n][amount] == infinity ? -1 : dp[n][amount];
    }
};

// TC: O(n * amount)
// SC: O(n * amount)