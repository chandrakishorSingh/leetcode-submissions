Solution 1:
​
- Observe that the AND of a series of numbers is never greater than the maximum number among them.
- Hence, the maximum possible bitwise AND of the required subarray will be equal to the maximum number of the array. Also, the subarray will only have elements as this maximum element because any smaller number will reduce the value of the bitwise AND of subarray.
- So, the problem reduces to finding the longest subarray with the elements equal to maximum element of the array.
​
```
class Solution {
public:
int longestSubarray(vector<int>& nums) {
int maxElement = *max_element(nums.begin(), nums.end());
int result = 1;
int count = 0;
for (int i = 0; i < nums.size(); i++) {
if (nums[i] == maxElement) {
count++;
} else {
count = 0;
}
result = max(result, count);
}
return result;
}
};
​
// TC: O(n)
// SC: O(1)
```