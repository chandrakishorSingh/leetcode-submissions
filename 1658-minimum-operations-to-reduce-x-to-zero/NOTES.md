Solution 1:
​
- We will iterate over the array from the left side and for every index `i`, will try to find `x - prefixSum[i]` from right.
- A map is used to keep track of suffix sums.
- Note that, we need to make sure that if we get any entry in map for a given prefix sum then that entry should only correspond to elements that are in the right of current index.
- That's the reason I've added `suffixSumToIndex[0] = n;` line and the second loop is starting from -1.
​
```
class Solution {
public:
int minOperations(vector<int>& nums, int x) {
int n = nums.size();
unordered_map<int, int> suffixSumToIndex;
suffixSumToIndex[0] = n;
int suffixSum = 0;
for (int i = n - 1; i >= 0; i--) {
suffixSum += nums[i];
suffixSumToIndex[suffixSum] = i;
}
int result = INT_MAX;
int prefixSum = 0;
for (int i = -1; i < n; i++) {
prefixSum += i >= 0 ? nums[i] : 0;
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