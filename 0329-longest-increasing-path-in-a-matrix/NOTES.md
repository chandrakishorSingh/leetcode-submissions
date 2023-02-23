TODO:
​
- try to understand first comment solution https://leetcode.com/problems/longest-increasing-path-in-a-matrix/discuss/78308/15ms-Concise-Java-Solution
​
Solution 1(Brute-Force, TLE):
​
- Apply DFS on every position, find out the longest increasing path originating from that position.
- Find maximum value among all such positions.
- I thought it's within TL as size of grid is small(`m, n <= 200`) but got TLE.
​
```
class Solution {
public:
int longestIncreasingPath(vector<vector<int>>& matrix) {
int m = matrix.size();
int n = matrix[0].size();
vector<vector<int>> visited(m, vector<int>(n));
int result = 0;
for (int i = 0; i < m; i++)
for (int j = 0; j < n; j++)
result = max(result, dfs(i, j, matrix, visited));
return result;