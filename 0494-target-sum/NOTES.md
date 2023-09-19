Solution 1:
​
- Brute-Force recursive solution.
- Explore all possible sign combinations.
​
```
class Solution {
public:
int _findTargetSumWays(vector<int>& nums, int target, int n) {
if (target == 0 && n == 0) {
return 1;
}
if (n == 0) {
return 0;
}
return _findTargetSumWays(nums, target - nums[n - 1], n - 1) + _findTargetSumWays(nums, target + nums[n - 1], n - 1);
}
int findTargetSumWays(vector<int>& nums, int target) {
int n = nums.size();
return _findTargetSumWays(nums, target, n);
}
};