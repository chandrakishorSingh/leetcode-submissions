NOTE:
​
- Very good explanation of when two pointer technique is valid and when not. https://leetcode.com/problems/subarray-sum-equals-k/discuss/301242/General-summary-of-what-kind-of-problem-can-cannot-solved-by-Two-Pointers
​
Solution 1(Brute-Force):
​
- Try all possible subarrays.
​
```
class Solution {
public:
int subarraySum(vector<int>& nums, int k) {
int n = nums.size();
int result = 0;
​
for (int i = 0; i < n; i++)
for (int j = i; j < n; j++)
if (accumulate(nums.begin() + i, nums.begin() + j + 1, 0) == k)
result++;
​
return result;
}
};
​
// TC: O(n^3)
// SC: O(1)
```
​
Solution 2:
​
- A better brute force.
- Instead of summing all the values of a subarray every time, we can use the sum of previous subarray to find the sum of current subarray.
​
```
class Solution {
public: