int pathLength = 1;
for (int i = 0; i < dx.size(); i++) {
int newRow = row + dx[i];
int newCol = col + dy[i];
if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n)
continue;
if (visited[newRow][newCol] != 1 && matrix[newRow][newCol] > matrix[row][col])
pathLength = max(pathLength, 1 + dfs(newRow, newCol, matrix, visited, dp));
}
visited[row][col] = 0;
dp[row][col] = pathLength;
return dp[row][col];
}
};
​
// TC: O(m * n)
// SC: O(m * n)
```
​
​
​
​
​
​
​
​
​
​
​