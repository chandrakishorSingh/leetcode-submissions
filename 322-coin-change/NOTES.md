TODO:
​
- interesting to do: https://leetcode.com/problems/coin-change/discuss/77426/C%2B%2B-DP-(46-ms-6-lines)-DFS-%2B-Memo-(155-ms-10-lines)-and-DFS-%2B-Pruning-(6-ms-9-lines)
​
Solution 1:
​
- It's not hard to see that it's not a greedy problem.
- And it's easy to see that DP will solve it.
- The recursive relation is simple.
-
```
coinChange(n, amount) = min(amount >= coins[n] ? 1 + coinChange(n, amount - coins[n]) : INFINITY, coinChange(n - 1, amount))
```
​
- At every decision, we have at most two choices. The worst case will happen when the coins and amount is such that it's not possible to get the change and the first element is the smallest one.
​
​
```
class Solution {
public:
int infinity = 1e4 + 1;
int coinChange(vector<int>& coins, int amount) {
auto result = dfs(coins.size() - 1, coins, amount);
return result == infinity ? -1 : result;