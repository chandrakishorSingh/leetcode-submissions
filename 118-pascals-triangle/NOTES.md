Solution 1:
​
- Simple recursive approach to generate all rows of pascal triangle till nth row
​
```
class Solution {
public:
vector<vector<int>> generate(int numRows) {
if (numRows == 1)
return {{1}};
auto rows = generate(numRows - 1);
rows.push_back({1});
for (int i = 1; i < numRows - 1; i++) {
rows[numRows - 1].push_back(rows[numRows - 2][i] + rows[numRows - 2][i - 1]);
}
rows[numRows - 1].push_back(1);
return rows;
}
};
​
// TC: O(n^2)
// SC: O(n) for call stack, except the output
```