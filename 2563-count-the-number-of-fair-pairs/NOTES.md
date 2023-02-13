TODO:
​
- Implement it : https://leetcode.com/problems/count-the-number-of-fair-pairs/discuss/3174181/Two-Pointers-*-2
​
Solution 1(Brute-Force, TLE):
​
- Just check the condition for all possible pairs of array.
​
```
class Solution {
public:
typedef long long ll;
long long countFairPairs(vector<int>& nums, int lower, int upper) {
int n = nums.size();
ll result = 0;
for (int i = 0; i < n - 1; i++) {
for (int j = i + 1; j < n; j++) {
int sum = nums[i] + nums[j];
if (sum >= lower && sum <= upper) {
result++;
}
}
}
return result;
}
};
​
// TC: O(n^2)