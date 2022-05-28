​
- Storing characters in a set as we are traversing through the string's substring. No need to check for `s[i:j + 1]` if `s[i:j]` already contains duplicates.
​
```
class Solution {
public:
int lengthOfLongestSubstring(string s) {
int result = 0;
​
set<char> st;
for (int i = 0; i < s.size(); i++) {
st.clear();
for (int j = i; j < s.size(); j++) {
if (st.count(s[j]))
break;
​
st.insert(s[j]);
result = max(result, j - i + 1);
}
}
return result;
}
};
​
// TC: O(n^2)
// SC: O(1)
```