TODO:
​
- Get the longest seq. length path
- Implement using BIT(https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326308/C%2B%2BPython-DP-Binary-Search-BIT-Solutions-Picture-explain-O(NlogN))
​
Solution 1(Brute-Force, TLE):
​
- Just check all possible increasing subsequences.
​
```
class Solution {
public:
int lengthOfLIS(vector<int>& nums) {
int result = 0;
for (int i = 0; i < nums.size(); i++) {
dfs(nums[i], i + 1, 1, nums, result);
}
return result;
}
void dfs(int prev, int index, int length, vector<int>& nums, int& result) {
if (index == nums.size()) {
result = max(result, length);
return;
}
if (prev < nums[index])
dfs(nums[index], index + 1, length + 1, nums, result);
dfs(prev, index + 1, length, nums, result);