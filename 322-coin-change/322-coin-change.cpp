class Solution {
public:
    int infinity = 1e4 + 1;
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        
        auto result = _coinChange(n, coins, amount, dp);
        
        return result == infinity ? -1 : result;
    }
    
    int _coinChange(int n, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (amount == 0)
            return 0;
        
        if (n == 0)
            return infinity;
        
        if (dp[n][amount] != -1)
            return dp[n][amount];
        
        int option1 = infinity;
        if (coins[n - 1] <= amount)
            option1 = 1 + _coinChange(n, coins, amount - coins[n - 1], dp);
        
        int option2 = _coinChange(n - 1, coins, amount, dp);
        
        dp[n][amount] = min(option1, option2);
        
        return dp[n][amount];
    }
};

// TC: O(2^(n + (amount / (min(coins[i])))))
// SC: O(n + (amount / min(coins[i])))