Solution 1:
​
- Straightforward solution
​
```
class Solution {
public:
int maximumWealth(vector<vector<int>>& accounts) {
int result = 0;
int m = accounts.size();
int n = accounts[0].size();
for (int i = 0; i < m; i++) {
result = max(result, accumulate(accounts[i].begin(), accounts[i].end(), 0));
}
return result;
}
};
​
// TC: O(m * n)
// SC: O(1)
```