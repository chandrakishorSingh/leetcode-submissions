Solution 1:
​
- Let `mn` be the minimum value of the given array. Then for this element, we can group those elements that are in the range of `[mn, mn + k]`. Note that there is no other range for `mn`  which can provide more elements than this range.
- Now, the problem is been reduced to a smaller instance.
- So, I've used sorting to find the smallest element each time.
​
```
class Solution {
public:
int partitionArray(vector<int>& nums, int k) {
sort(nums.begin(), nums.end());
int result = 1;
int anchor = nums[0];
for (auto num: nums) {
if (num - anchor <= k)
continue;
anchor = num;
result++;
}
return result;
}
};
​
// TC: O(n * log(n))
// SC: O(1)
```