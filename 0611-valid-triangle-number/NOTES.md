sort(nums.begin(), nums.end());
int n = nums.size();
int result = 0;
for (int i = 0; i < n; i++) {
for (int j = i + 1; j < n; j++) {
auto k = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]) - nums.begin();
result += k - j - 1;
}
}
return result;
}
};
​
// TC: O(n^2 * log(n))
// SC: O(log(n)), usually sorting algo. uses log(n) of recursive stack space
```
​
Solution 4:
​
- We can also use a linear search instead of binary search to find the third side of the triangle. Obviously, it will be slow.
​
```
class Solution {
public:
int triangleNumber(vector<int>& nums) {
sort(nums.begin(), nums.end());
int result = 0;
for (int i = 0; i < nums.size(); i++) {
for (int j = i + 1; j < nums.size(); j++) {
int k = j + 1;
while ((k < nums.size()) && (nums[i] + nums[j] > nums[k])) {
k++;