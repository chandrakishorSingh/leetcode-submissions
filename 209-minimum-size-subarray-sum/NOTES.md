TODO:
​
- Do the follow up of O(n * log(n)) and see other approaches
​
Solution 1:
​
- Sliding window.
- If the sum of `arr[i:j] >= target` then no need to look for `arr[i:j + k]`. Also, no need to start from `i + 1:` as `arr[i + 1: j - 1]` is already less than target.
- Hence, if we found a solution `arr[i:j]`, then we should check for `arr[i + 1: j]`. If it's not a solution then we keep increasing the sum otherwise `arr[i + 1: j]` will be a solution and so we would not need to look for `arr[i + 1: j + k]`.
​
```
class Solution {
public:
int minSubArrayLen(int target, vector<int>& nums) {
int n = nums.size();
int result = INT_MAX;
int start = 0;
int sum = 0;
for (int end = 0; end < n; end++) {
if (sum + nums[end] < target) {
sum += nums[end];
continue;
}
sum += nums[end];
while (sum >= target) {
result = min(result, end - start + 1);
sum -= nums[start++];
}
}
return result == INT_MAX ? 0: result;
}
};
​
// TC: O(n)
// SC: O(1)
```