Solution 1:
​
- Use a different matrix for output
​
```
class Solution {
public:
vector<vector<int>> transpose(vector<vector<int>>& matrix) {
int n = matrix.size();
int m = matrix[0].size();
vector<vector<int>> result(m, vector<int>(n));
for (int i = 0; i < n; i++)
for (int j = 0; j < m; j++)
result[j][i] = matrix[i][j];
return result;
}
};
​
// TC: O(n * m)
// SC: O(n * m)
```
​
Solution 2:
​
​