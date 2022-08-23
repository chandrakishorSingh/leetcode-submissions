dp[i][j] = min(j >= coins[i - 1] ? 1 + dp[i][j - coins[i - 1]] : dp[i - 1][j], dp[i - 1][j]);
return dp[n][amount] == infinity ? -1 : dp[n][amount];
}
};
​
// TC: O(n * amount)
// SC: O(n * amount)
```
​
Solution 4(Space optimized):
​
- It's easy to see that in the Bottom-Up approach, the two values that we might need lies in the left of the current cell in the same row or directly above of the current cell.
- So, we can just use one row of length `amount + 1` to store the states of the DP. And iterate over this row for each of the indices of `coins`, i.e., we will gradually add one coin at a time and will see what is the minimum number of coins needed for particular amount.
- Also, note that similar to above approach, it's not possible to use a vertical strip, i.e., an array of length `n + 1`, and iterate over all possible amount at a time. This is because unlike in the previous case where the position of one of the cell was fixed(always directly above the current cell), in this case the position of the cell will be left of the current cell by `coins[i]` steps. So, it's not fixed and hence we don't know how much older info. we might need to store.
​
```
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
​
// TC: O(n * amount)
// SC: O(amount)
```