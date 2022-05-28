```
​
Solution 2(Brute-Force):
​
- Check all possible substrings
​
```
class Solution {
public:
int lengthOfLongestSubstring(string s) {
int result = 0;
for (int i = 0; i < s.size(); i++) {
for (int j = i; j < s.size(); j++) {
if (!containsDuplicates(s, i, j))
result = max(result, j - i + 1);
else
break;
}
}
return result;
}
bool containsDuplicates(string& s, int start, int end) {
set<char> st;
for (int i = start; i <= end; i++) {
if (st.count(s[i]))
return true;
st.insert(s[i]);
}
return false;
}
};
​
// TC: O(n^3)
// SC: O(1)
```