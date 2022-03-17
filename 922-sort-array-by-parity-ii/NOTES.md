Solution 1:
​
- If `k` even numbers are present at the odd position then `k` odd numbers are also present at the even positions and vice-versa.
- Just using two pointers to track even and odd positions are enough.
​
```
class Solution {
public:
vector<int> sortArrayByParityII(vector<int>& nums) {
int evenIndex = 0;
int oddIndex = 1;
for (int i = 0; i < nums.size(); i++) {
if (i % 2 == 1) {
if (nums[i] % 2 == 1)
continue;
while (nums[evenIndex] % 2 == 0) {
evenIndex += 2;
}
swap(nums[i], nums[evenIndex]);
evenIndex += 2;
} else {
if (nums[i] % 2 == 0)
continue;
while (nums[oddIndex] % 2 == 1)
oddIndex += 2;
swap(nums[i], nums[oddIndex]);
oddIndex += 2;
}
}
return nums;
}
};
​
// TC: O(n)
// SC: O(1)
```