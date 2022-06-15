// TC: O(n)
// SC: O(n)
```
​
Solution 2:
​
- Recursive version of the above same approach.
​
```
class Solution {
public:
int rob(vector<int>& nums) {
return _rob(nums.size(), nums);
}
int _rob(int n, vector<int>& nums) {
if (n == 0)
return 0;
if (n == 1)
return nums[0];
return max(nums[n - 1] + _rob(n - 2, nums), _rob(n - 1, nums));
}
};
​
// TC: O(2^n)
// SC: O(n)
```