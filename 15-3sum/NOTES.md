Solution 1:
​
- Just find all triplets which sum to 0.
- But be careful of not adding the duplicate triplets. This can be easily achieved by sorting all numbers initially and using a set of vector to store those triplets.
​
```
class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
sort(nums.begin(), nums.end());
set<vector<int>> triplets;
for (int i = 0; i < nums.size(); i++)
for (int j = i + 1; j < nums.size(); j++)
for (int k = j + 1; k < nums.size(); k++)
if (nums[i] + nums[j] + nums[k] == 0)
triplets.insert({nums[i], nums[j], nums[k]});
vector<vector<int>> result(triplets.begin(), triplets.end());
return result;
}
};
​
// TC: O(n^3 * log(n))
// SC: O(n^3)
```
​
Solution 2:
​
- Since the numbers are already sorted, we can use binary search to find the third element for every possible pair we could make from the array elements.
- And to be sure that we don't include duplicate triplets, we can remember the last pair we used and make sure that the next pair is different from this one. Since the array is already sorted it's easier to check whether current pair is same as previous one or not.
​
```
class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
sort(nums.begin(), nums.end());
int first = nums[0] - 1;
int second = first;
set<vector<int>> result;