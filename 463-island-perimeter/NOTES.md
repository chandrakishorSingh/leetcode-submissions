Solution 1:
​
- Just visit every land cell and check whether each of its 4 sides are touching water or boundary of the grid.
​
```
class Solution {
public:
int islandPerimeter(vector<vector<int>>& grid) {
int rows = grid.size();
int cols = grid[0].size();
int result = 0;
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
if (grid[i][j] == 0)
continue;
vector<int> dx = {0, -1, 0, 1};
vector<int> dy = {-1, 0, 1, 0};
for (int k = 0; k < dx.size(); k++) {
int newRow = i + dx[k];
int newCol = j + dy[k];
result += (newRow < 0) ? 1 : 0;
result += (newRow >= rows) ? 1 : 0;
result += (newCol < 0) ? 1 : 0;
result += (newCol >= cols) ? 1 : 0;
result += (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 0) ? 1 : 0;
}
}
}
return result;
}
};
​
// TC: O(m * n), m and n are # of rows and cols of grid respectively
// SC: O(1)
```