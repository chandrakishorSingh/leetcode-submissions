if (suffixSumToIndex.count(x - prefixSum) && i < suffixSumToIndex[x - prefixSum])
result = min(result,  i + 1 + n - suffixSumToIndex[x - prefixSum]);
}
return result == INT_MAX ? -1: result;
}
};
​
// TC: O(n) on average
// SC: O(n)
```
​
Solution 2:
​
- Same idea as above but using binary search to find the required suffix sum.
- Better than dictionary based approach in terms of actual runtime.
​
```
class Solution {
public:
int minOperations(vector<int>& nums, int x) {
int n = nums.size();
​
vector<int> suffixSum(n + 1);
for (int i = n - 1; i >= 0; i--)
suffixSum[i] += suffixSum[i + 1] + nums[i];
int result = INT_MAX;
int prefixSum = 0;
for (int i = 0; i <= n; i++) {
prefixSum += i > 0 ? nums[i - 1] : 0;
int low = i;
int high = n;
int index = binarySearch(low, high, x - prefixSum, suffixSum);
if (index != -1)