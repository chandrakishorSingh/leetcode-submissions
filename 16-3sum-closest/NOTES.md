Solution 1(Brute-Force, TLE):
​
- Check all possible triplets.
​
```
class Solution {
public:
int threeSumClosest(vector<int>& nums, int target) {
int result = nums[0] + nums[1] + nums[2];
for (int i = 0; i < nums.size(); i++)
for (int j = i + 1; j < nums.size(); j++)
for (int k = j + 1; k < nums.size(); k++)
if (abs(nums[i] + nums[j] + nums[k] - target) < abs(result - target))
result = nums[i] + nums[j] + nums[k];
return result;
}
};
​
// TC: O(n^3)
// SC: O(1)
```
​
```
class Solution {
public:
int threeSumClosest(vector<int>& nums, int target) {
sort(nums.begin(), nums.end());
int result = nums[0] + nums[1] + nums[2];
for (int i = 0; i < nums.size() - 2; i++) {
if (result == target)
break;
if (i > 0 && nums[i] == nums[i - 1])
continue;
auto closestSum = twoSum(target - nums[i], i + 1, nums, result);
if (abs(result - target) > abs(nums[i] + closestSum - target))
result = nums[i] + closestSum;
}