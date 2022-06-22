public:
int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
return dfs(heights, bricks, ladders, 1);
}
int dfs(vector<int>& heights, int bricks, int ladders, int pos) {
if (pos == heights.size())
return pos - 1;
if (heights[pos] <= heights[pos - 1])
return dfs(heights, bricks, ladders, pos + 1);
int option1 = -1;
if (bricks >= heights[pos] - heights[pos - 1])
option1 = dfs(heights, bricks - heights[pos] + heights[pos - 1], ladders, pos + 1);
int option2 = -1;
if (ladders > 0)
option2 = dfs(heights, bricks, ladders - 1, pos + 1);
return max({ pos - 1, option1, option2 });
}
};
​
// TC: O(2^n)
// SC: O(n)
// n = len(heights)
```
​
​
Solution 2(Top-Down DP, MLE):
​
```
class Solution {
public:
typedef vector<vector<vector<int>>> vec3d;
int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
int n = heights.size();
vec3d store(n, vector<vector<int>>(bricks + 1, vector<int>(ladders + 1, -1)));
solve(store, heights, n - 1, bricks, ladders);
int result = INT_MIN;
for (int i = 0; i < n; i++)
if (store[i][bricks][ladders])
result = i;
return result;
}
int solve(vec3d& store, vector<int>& heights, int n, int bricks, int ladders) {
if (store[n][bricks][ladders] != -1)
return store[n][bricks][ladders];