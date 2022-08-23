class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int infinity = 1e4 + 1;
        
        vector<int> dp(amount + 1, infinity);
        dp[0] = 0;
        
        for (int i = 0; i < coins.size(); i++)
            for (int j = 1; j <= amount; j++)
                dp[j] = min(dp[j], j >= coins[i] ? (1 + dp[j - coins[i]]) : dp[j]);
        
        return dp[amount] == infinity ? -1 : dp[amount];
    }
};

// TC: O(n * amount)
// SC: O(amount)