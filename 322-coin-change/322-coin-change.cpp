class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int infinity = 1e4 + 1;
        
        vector<int> dp(amount + 1, infinity);
        dp[0] = 0;
        
        for (int i = 0; i < coins.size(); i++)
            for (int j = 1; j <= amount; j++)
                if (j >= coins[i] && dp[j - coins[i]] != infinity)
                    dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
        
        return dp[amount] == infinity ? -1: dp[amount];
    }
};