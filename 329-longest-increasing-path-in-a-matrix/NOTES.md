}
int dfs(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& visited) {
visited[row][col] = 1;
vector<int> dx = {0, -1, 0, 1};
vector<int> dy = {1, 0, -1, 0};
int m = matrix.size();
int n = matrix[0].size();
int pathLength = 0;
for (int i = 0; i < dx.size(); i++) {
int newRow = row + dx[i];
int newCol = col + dy[i];
​
if ((newRow >= 0 && newRow < m) && (newCol >= 0 && newCol < n))
if (visited[newRow][newCol] != 1 && matrix[newRow][newCol] > matrix[row][col])
pathLength = max(pathLength, dfs(newRow, newCol, matrix, visited));
}
visited[row][col] = 0;
return 1 + pathLength;
}
};
​
// TC: O(m*n * m*n)
// SC: O(m*n)
```