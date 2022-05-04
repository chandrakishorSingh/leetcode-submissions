Solution 1(TLE):
​
- Just go over every possible distinct pair and see whether their sum is `k`. A pair `(a, b)` is called distinct from other pair `(c, d)` if all indices, i.e., `a, b, c, d` are different.
- To remember which indices have been already taken to form some pair, invert the sign of element(as every element is > 0, so easy to recognise which has been taken out)
​
```
class Solution {
public:
int maxOperations(vector<int>& nums, int k) {
int n = nums.size();
int count = 0;
for (int i = 0; i < n; i++) {
if (nums[i] < 0)
continue;
for (int j = i + 1; j < n; j++) {
if (nums[j] < 0)
continue;
if (nums[i] + nums[j] == k) {
count++;
nums[i] = -nums[i];
nums[j] = -nums[j];
break;
}
}
}
return count;
}
};
​
// TC: O(n^2)
// SC: O(1)
```