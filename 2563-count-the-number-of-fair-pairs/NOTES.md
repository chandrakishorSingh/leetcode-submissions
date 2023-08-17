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
// SC: O(1)
```
​
Solution 2:
​
- It's easy to see that if the elements were sorted then for each element x we could find all element y such that it's to the right of x and their sum satisfy the required criteria.
- But if we sort the array then it could be possible that the elements which were left to an element is now at the right of that element(because it was greater than this element).
- Observe that, even in this situation we can count this pair because at the end of the day we just need a pair of the elements which satisfy the condition.