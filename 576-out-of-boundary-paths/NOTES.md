Solution 1(Brute-Force, TLE):
​
- Every call to `dfs` can make at most 4 more calls.
- The "chain of calls" will not have length greater than `maxMove`.
​
```
class Solution {
public:
int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
return dfs(m, n, maxMove, startRow, startColumn);
}
int dfs(int m, int n, int remainingMoveCount, int currentRow, int currentColumn) {
if (currentRow < 0 || currentRow >= m || currentColumn < 0 || currentColumn >= n)
return 1;
int result = 0;
if (remainingMoveCount > 0) {
result += dfs(m, n, remainingMoveCount - 1, currentRow - 1, currentColumn);
result += dfs(m, n, remainingMoveCount - 1, currentRow, currentColumn + 1);
result += dfs(m, n, remainingMoveCount - 1, currentRow + 1, currentColumn);
result += dfs(m, n, remainingMoveCount - 1, currentRow, currentColumn - 1);
}
return result;
}