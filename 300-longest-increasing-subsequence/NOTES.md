dfs(prev, index + 1, length, nums, result);
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
vector<int> dp(nums.size(), 1);
int result = 1;
for (int i = 0; i < nums.size(); i++) {
for (int j = i - 1; j >= 0; j--) {
if (nums[j] < nums[i]) {
dp[i] = max(dp[i], dp[j] + 1);
}
}
result = max(result, dp[i]);
}
return result;
}
};
​
// TC: O(n^2)
// SC: O(n)
```