Solution 1:
​
- It's easy to see that it can be solved using sliding window.
- Let `x = cumulative AND of arr[i:j]`. If arr[i:j] is a nice array then arr[i:j+1] will also be nice if `x` and arr[j+1] does not have any set bit in common. This can easily be checked in O(1).
- Also, if they have a set bit in common then we have to reduce the size of the array from left by "reversing the operation". That means somehow we have to find the cumulative AND value of arr[i+1: j] using cumulative AND of arr[i:j].
- This can be done by removing all set bits of arr[i] from `x` which can be done using `x = x ^ arr[i]`.
​
```
class Solution {
public:
int longestNiceSubarray(vector<int>& nums) {
int result = 0;
int start = 0;
int cumulativeOR = 0;
for (int end = 0; end < nums.size(); end++) {
while ( isSetBitIntersects(cumulativeOR, nums[end]) ) {
cumulativeOR ^= nums[start++];
}
cumulativeOR |= nums[end];
result = max(result, end - start + 1);
}
return result;
}
bool isSetBitIntersects(int num1, int num2) {
for (int i = 31; i >= 0; i--) {
auto bit1 = (num1 & (1 << i)) > 0 ? 1 : 0;
auto bit2 = (num2 & (1 << i)) > 0 ? 1 : 0;
if (bit1 == 1 && bit2 == 1)
return true;
}
return false;
}
};
​
// TC: O(n)
// SC: O(1)
```