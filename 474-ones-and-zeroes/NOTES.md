for (int i = 0; i < size; i++) {
bitCount[0][i] = count(strs[i].begin(), strs[i].end(), '0');
bitCount[1][i] = strs[i].size() - bitCount[0][i];
}
vector3d dp(size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
return _findMaxForm(size, m, n, bitCount, dp);
}
int _findMaxForm(int index, int m, int n, vector<vector<int>>& bitCount, vector3d& dp) {
if (index == 0)
return 0;
if (dp[index][m][n] != -1)
return dp[index][m][n];
int option1 = 0;
int option2 = 0;
if (bitCount[0][index - 1] <= m && bitCount[1][index - 1] <= n)
option1 = 1 + _findMaxForm(index - 1, m - bitCount[0][index - 1], n - bitCount[1][index - 1], bitCount, dp);
option2 = _findMaxForm(index - 1, m, n, bitCount, dp);
dp[index][m][n] = max(option1, option2);
return dp[index][m][n];
}
};
​
// TC: O(size * m * n)
// SC: O(size * m * n)
```
​
Solution 4:
​
- Bottom-Up DP version.
​
​