return result == infinity ? -1 : result;
}
int _coinChange(int n, vector<int>& coins, int amount, vector<vector<int>>& dp) {
if (amount == 0)
return 0;
if (n == 0)
return infinity;
if (dp[n][amount] != -1)
return dp[n][amount];
int option1 = _coinChange(n - 1, coins, amount, dp);
int option2 = option1;
if (coins[n - 1] <= amount)
option2 = 1 + _coinChange(n, coins, amount - coins[n - 1], dp);
dp[n][amount] = min(option1, option2);
return dp[n][amount];
}
};
​
// TC: O(n * amount)
// SC: O(n * amount)
```
​
​