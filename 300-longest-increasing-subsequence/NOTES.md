}
};
​
// TC: O(2^n)
// SC: O(n)
```
​
Solution 2:
​
- Store the length of longest increasing subsequence that ends at each of the index in some auxilary array. The maximum among those values will be the result.
- This can be done in O(n^2) time as we only need to examine all elements that are in the left of current position.
​
```
class Solution {
public:
int lengthOfLIS(vector<int>& nums) {
int n = nums.size();
vector<int> dp(n);
int result = 0;
for (int i = 0; i < n; i++) {
int maxLength = 0;
for (int j = i - 1; j >= 0; j--) {
if (nums[j] < nums[i]) {
maxLength = max(maxLength, dp[j]);
}
}
dp[i] = maxLength + 1;
result = max(result, dp[i]);
}
return result;
}
};
​
// TC: O(n^2)
// SC: O(n)
```