Solution 1:
​
- Simple Top-Down DP approach
​
```
class Solution {
public:
int uniquePaths(int m, int n) {
vector<vector<int>> store(m, vector<int>(n, -1));
return explore(m - 1, n - 1, store);
}
int explore(int i, int j, vector<vector<int>>& store) {
if (store[i][j] != -1)
return store[i][j];
if (i == 0 || j == 0) {
return 1;
}
store[i][j] = explore(i - 1, j, store) + explore(i, j - 1, store);
return store[i][j];
}
};