Solution 1:
​
- Simple recursive way.
​
```
class Solution {
public:
int minMaxGame(vector<int>& nums) {
return _minMaxGame(nums, nums.size());
}
int _minMaxGame(vector<int>& nums, int size) {
if (size == 1)
return nums[0];
int pairty = 0;
for (int i = 0; i < size / 2; i++) {
if (!pairty)
nums[i] = min(nums[2 * i], nums[2 * i + 1]);
else
nums[i] = max(nums[2 * i], nums[2 * i + 1]);
pairty = 1 - pairty;
}
return _minMaxGame(nums, size / 2);
}
};
​
// TC: O(n)
// SC: O(log(n))
```