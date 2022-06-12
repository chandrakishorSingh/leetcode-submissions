Solution 1:
​
- It's very similar to finding the largest subarray without repeating character problem.
- In that problem, we were able to examine all subarrays without repeating character using sliding window(with the help of a dictionary to check for repeated characters)
- We can use the same technique of traversal to get the maximum possible sum of those subarrays.
​
```
class Solution {
public:
int maximumUniqueSubarray(vector<int>& nums) {
int n = nums.size();
int result = 0;
int sum = 0;
int start = 0;
unordered_map<int, int> lastIndex;
for (int end = 0; end < n; end++) {
if (lastIndex.count(nums[end])) {
int newStart = lastIndex[nums[end]] + 1;
while (start != newStart) {
sum -= nums[start];
lastIndex.erase(nums[start]);
start++;
}
}
​
lastIndex[nums[end]] = end;
sum += nums[end];
result = max(result, sum);
}
return result;
}
};
​
// TC: O(n)
// SC: O(n)
```