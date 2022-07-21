Solution 1(Brute-Force, TLE):
​
- Check all possible subsequences.
​
```
class Solution {
public:
bool isSubsequence(string s, string t) {
vector<char> subSequence;
return dfs(s, t, subSequence, 0);
}
bool dfs(string& s, string& t, vector<char>& subSequence, int index) {
if (subSequence.size() == s.size()) {
return string(subSequence.begin(), subSequence.end()) == s;
}
if (index == t.size())
return false;
bool result = false;
​
subSequence.push_back(t[index]);
result |= dfs(s, t, subSequence, index + 1);
if (result)
return result;
subSequence.pop_back();
result |= dfs(s, t, subSequence, index + 1);
return result;
}
};
​
// TC: O(2^n * n)
// SC: O(n)
// n = length of t
```