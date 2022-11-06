TODO:
​
- See other solutions.
​
NOTE:
​
- Need to improve my implementation skill of sliding window.
​
Solution 1:
​
- Straightforward sliding window problem.
​
```
class Solution {
public:
long long maximumSubarraySum(vector<int>& nums, int k) {
int n = nums.size();
long long result = 0;
int start = 0;
long long sum = 0;
unordered_set<int> seen;
for (int end = 0; end < n; end++) {
if (end - start + 1 > k) {
seen.erase(nums[start]);
sum -= nums[start++];
}
if (seen.count(nums[end])) {
sum = nums[end];
start = end;
seen.clear();
seen.insert(nums[end]);
continue;
}
seen.insert(nums[end]);
sum += nums[end];
if (end - start + 1 == k)
result = max(result, sum);
}
return result;
}
};
​
// TC: Θ(n)
// SC: O(n)
```