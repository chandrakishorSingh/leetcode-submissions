Solution 1:
​
- Using sum
​
```
class Solution {
public:
int missingNumber(vector<int>& nums) {
int n = nums.size();
int sum = accumulate(nums.begin(), nums.end(), 0);
return (n * (n + 1) / 2) - sum;
}
};
​
// TC: O(n)
// SC: O(1)
```
​
Solution 2:
​
- Using xor.
- It's better than 1st because xor is usually fast than addition and also we don't need to worry about overflow.
​
```
class Solution {
public:
int missingNumber(vector<int>& nums) {
int result = 0;
for (int i = 1; i <= nums.size(); i++) {
result ^= i;
result ^= nums[i - 1];
}
return result;
}
};
​
// TC: O(n)
// SC: O(1)
```