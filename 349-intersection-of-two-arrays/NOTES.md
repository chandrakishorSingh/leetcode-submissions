Solution 1:
​
- Use a set.
​
```
class Solution {
public:
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
set<int> st(nums1.begin(), nums1.end());
vector<int> result;
for (auto num: nums2) {
if (st.count(num)) {
result.push_back(num);
st.erase(num);
}
}
return result;
}
};
​
// TC: O(n*log(n) + m * log(n))
// SC: O(n)
// n, m are size of two arrays
```