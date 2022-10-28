Solution 1:
​
- Use a set to store numbers and to query for negatives.
​
```
class Solution {
public:
int findMaxK(vector<int>& nums) {
set<int> st;
int result = -1;
for (auto num: nums) {
st.insert(num);
if (st.count(num) && st.count(-num))
result = max(result, abs(num));
}
return result;
}
};
​
// TC: O(n * log(n))
// SC: O(n)
```