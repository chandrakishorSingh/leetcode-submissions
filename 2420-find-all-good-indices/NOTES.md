Solution 1:
​
- If we know, at every index, the count of elements that are in non-increasing order starting the current element to it's left and the count of elements that are in non-decreasing order starting from the current element to it's right then it's easy to calculate the answer of the given question.
- So, we'll store such counts using two arrays. One for counting elements that are in non-increasing order starting the current element to it's left and the other for counting the elements that are in non-decreasing order starting from the current element to it's right.
​
```
class Solution {
public:
vector<int> goodIndices(vector<int>& nums, int k) {
int n = nums.size();
int count = 0;
vector<int> prefix(n);
for (int i = 1; i < n; i++) {
count = nums[i] <= nums[i - 1] ? count + 1: 0;
prefix[i] = count;
}
count = 0;
vector<int> suffix(n);
for (int i = n - 2; i >= 0; i--) {
count = nums[i] <= nums[i + 1] ? count + 1: 0;
suffix[i] = count;
}
vector<int> result;
for (int i = k; i < n - k; i++) {
if ((prefix[i - 1] >= k - 1) and (suffix[i + 1] >= k - 1))
result.push_back(i);
}
return result;
}
};
​
// TC: O(n)
// SC: O(n)
```