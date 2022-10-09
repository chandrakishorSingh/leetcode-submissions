Solution 1:
​
- If we are at `grid[i][j]`, we need to know how many paths that end at `grid[i - 1][j]` and `grid[i][j - 1]` have path sum with remainder equal to "complement" of the remainder of the number at `grid[i][j]`.
- This gives the idea that we should know, at each of the grid position, the number of paths that ends at that position and what is the remainder of the path sum of those paths.
​
```
class Solution {
public:
int numberOfPaths(vector<vector<int>>& grid, int k) {
int m = grid.size();
int n = grid[0].size();
vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k)));
int sum = 0;
for (int i = 0; i < m; i++) {
sum += grid[i][0];
dp[i][0][sum % k] = 1;
}
sum = 0;
for (int j = 0; j < n; j++) {
sum += grid[0][j];
dp[0][j][sum % k] = 1;
}
int mod = 1e9 + 7;
for (int i = 1; i < m; i++) {
for (int j = 1; j < n; j++) {
for (int r = 0; r < k; r++) {
int newRemainder = (r + (grid[i][j] % k)) % k;
​
dp[i][j][newRemainder] = (dp[i - 1][j][r] + dp[i][j - 1][r]) % mod;
}
}
}
return dp[m - 1][n - 1][0];
}
};
​
// TC: O(n * m * k)
// SC: O(n * m * k)
```