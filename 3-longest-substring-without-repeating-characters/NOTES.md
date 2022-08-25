Solution 1:
​
- Two pointer/sliding window approach
- If `s[i:j]` contains duplicate then so is `s[i:j + 1]`, `s[i:j + 2]`, `s[i:j + 3]`, ... Hence, no need to check those extra substrings.
- Use `start` and `end` pointers. Iterate over the string using end pointer. If a duplicate is found then increment start till it get past the previous duplicate. Hence, in either case(s[end] being duplicate or not), one of the pointer is moved right side. So, the algorithm will take linear time.
​
```
class Solution {
public:
int lengthOfLongestSubstring(string s) {
int result = 0;
unordered_map<char, int> lastIndex;
int start = 0;
int end = 0;
for (; end < s.size(); end++) {
if (lastIndex.count(s[end])) {
while (start <= lastIndex[s[end]])
lastIndex.erase(s[start++]);
}
lastIndex[s[end]] = end;
result = max(result, end - start + 1);
}
return result;
}
};
​
// TC: O(n)
// SC: O(# unique chars in s)
```
​
Solution 2(Brute-Force):