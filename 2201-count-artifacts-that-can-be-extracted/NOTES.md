// TC: O(n^2 * log(n))
// SC: O(n^2)
```
​
Solution 3:
​
- Based on prefix sum
- Create a prefix sum matrix for grid where initially the cells that belong to `dig` are 1 and all other 0. So, `grid[i][j]` gives the sum of all cells from `(0, 0)` to `(i, j)`, going in row-major order, of course.
- An artifact will be completely uncovered if area of artifact equals the sum of cells of grid formed by corner points of that artifact.
​
```
class Solution {
public:
int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
vector<vector<int>> grid(n, vector<int>(n));
for (auto& cell: dig)
grid[cell[0]][cell[1]] = 1;
for (int i = 1; i < n; i++)
grid[i][0] += grid[i - 1][0];
for (int i = 1; i < n; i++)
grid[0][i] += grid[0][i - 1];
for (int i = 1; i < n; i++) {
for (int j = 1; j < n; j++) {
grid[i][j] = grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1] + grid[i][j];
}
}
int result = 0;
for (auto& artifact: artifacts) {
int r1 = artifact[0];
int c1 = artifact[1];
int r2 = artifact[2];
int c2 = artifact[3];