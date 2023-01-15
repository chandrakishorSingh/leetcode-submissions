```
class Solution {
public:
vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
vector<vector<int>> result(n, vector<int>(n));
​
for (auto& query: queries) {
int row1 = query[0];
int col1 = query[1];
int row2 = query[2];
int col2 = query[3];
for (int i = row1; i <= row2; i++) {
result[i][col1] += 1;
if (col2 + 1 < n) {
result[i][col2 + 1] -= 1;
}
}
}
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
result[i][j] += (j != 0) ? result[i][j - 1] : 0;
}
}
​
return result;
}
};
​
// TC: O(n^2 + len(queries) * n)
// SC: O(1)
```