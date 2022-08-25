for (int i = 0; i <= n2; i++)
dp[0][i] = i;
for (int i = 1; i <= n1; i++)
for (int j = 1; j <= n2; j++)
dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : 1 + min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
return dp[n1][n2];
}
};
​
// TC: O(n1 * n2)
// SC: O(n1 * n2)
```
​
Solution 4:
​
- With little observation, it's easy to see that we can optimize the space to `O(n2)`.
- I think it's also possible to optimize the space to `O(n1)` but in that case, we have to traverse the states in "column" fashion rather than "row" fashion as done in this solution.
​
```
class Solution {
public:
int minDistance(string word1, string word2) {
int n1 = word1.size();
int n2 = word2.size();
vector<int> dp(n2 + 1);
for (int i = 0; i <= n2; i++)
dp[i] = i;
for (int i = 1; i <= n1; i++) {
int prev = dp[0];
dp[0] = i;
for (int j = 1; j <= n2; j++) {
int temp = dp[j];
dp[j] = word1[i - 1] == word2[j - 1] ? prev : 1 + min({ dp[j], dp[j - 1], prev });
prev = temp;
}
}
return dp[n2];
}
};
​
// TC: O(n1 * n2)
// SC: O(n2)
```