Solution 1:
​
- Sort and return element at the `n - k` position.
​
```
class Solution {
public:
int findKthLargest(vector<int>& nums, int k) {
sort(nums.begin(), nums.end());
return nums[nums.size() - k];
}
};
// TC: O(n * log(n))
// SC: O(1)
```
​
​
Solution 2:
​
- Using built-in `nth_element()`
​
```
class Solution {
public:
int findKthLargest(vector<int>& nums, int k) {
nth_element(nums.begin(), nums.end() - k, nums.end());
return nums[nums.size() - k];
}
};
​
// TC: O(n) on average
// SC: O(1)
```