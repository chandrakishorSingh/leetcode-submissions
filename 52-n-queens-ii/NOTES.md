Solution 1:
​
- Same as [this](https://leetcode.com/problems/n-queens/)
​
```
class Solution {
public:
int totalNQueens(int n) {
int result = 0;
vector<int> queenPositions;
backtrack(0, n, queenPositions, result);
return result;
}
void backtrack(int row, int n, vector<int>& queenPositions, int& result) {
if (row == n) {
result++;
return;
}
for (int i = 0; i < n; i++) {
if (canPlace(i, queenPositions)) {
queenPositions.push_back(i);
backtrack(row + 1, n, queenPositions, result);