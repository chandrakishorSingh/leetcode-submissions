- If we know the result for the subarray till `i` then how to find the result for subarray till `i + 1`(or greater) ?
- We need few pieces of information here to optimally find the result as the size of array grows.
- We can easily get the highest index that can be reached with no jump initially. Then, to reach any index greater than that, we need to make a jump from any of the previous indices. Remember that for those indices, we already know the optimal result. Hence, as soon as our current index reach exceeds, we will update it by the maximum reach that can be obtained from the indices that we have already seen.
​
```
class Solution {
public:
int jump(vector<int>& nums) {
int currentJumpReach = 0;
int nextJumpReach = nums[0];
int result = 0;
​
int n = nums.size();
for (int i = 0; i < n; i++) {
if (i > currentJumpReach) {
currentJumpReach = nextJumpReach;
result++;
}
nextJumpReach = max(nextJumpReach, i + nums[i]);
}
return result;
}
};
​
// TC: O(n)
// SC: O(1)
```