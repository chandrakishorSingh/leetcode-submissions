Solution 1:
​
- Just insert all the numbers to a set. Then insert reverse of all the numbers to the same set. The number of elements in the set will be the final answer.
​
```
class Solution {
public:
int countDistinctIntegers(vector<int>& nums) {
set<int> st(nums.begin(), nums.end());
for (auto num: nums) {
auto numString = to_string(num);
reverse(numString.begin(), numString.end());
st.insert(stoi(numString));
}
return st.size();
}
};
​
// TC: O(n * log(n))
// SC: O(n)
```