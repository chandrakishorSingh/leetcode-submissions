Solution 1:
​
- Just find sum of all subarrays of length 2 and check whether there is any duplicates.
​
```
class Solution {
public:
bool findSubarrays(vector<int>& nums) {
bool result = false;
unordered_set<int> st;
for (int i = 1; i < nums.size(); i++) {
int sum = nums[i] + nums[i - 1];
if (st.count(sum)) {
result = true;
break;
}
st.insert(sum);
}
return result;
}
};
​
// TC: O(n)
// SC: O(1)
```
​
Solution 2(Brute-Force):
​
- Check every subarray of length 2 with every other subarray of length 2.
​
```
class Solution {
public:
bool findSubarrays(vector<int>& nums) {
for (int i = 0; i < nums.size() - 2; i++) {
for (int j = i + 1; j < nums.size() - 1; j++) {
if ((nums[i] + nums[i + 1]) == (nums[j] + nums[j + 1]))
return true;
}
}
return false;
}
};
​
// TC: O(n^2)
// SC: O(1)
```