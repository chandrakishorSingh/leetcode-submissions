Solution 1:
​
- Simple DFS.
- Modifying input(but restoring after finding the result).
- Recursive call stack won't have a length greater than the number of cells in the grid.
​
```
class Solution {
public:
int maxAreaOfIsland(vector<vector<int>>& grid) {
int m = grid.size();
int n = grid[0].size();
int result = 0;
for (int i = 0; i < m; i++)
for (int j = 0; j < n; j++)
result = max(result, dfs(i, j, grid));
return result;
}
int dfs(int row, int col, vector<vector<int>>& grid) {
int m = grid.size();
int n = grid[0].size();
if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == -1 || grid[row][col] == 0)