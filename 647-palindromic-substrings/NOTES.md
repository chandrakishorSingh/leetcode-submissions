Solution 1(Brute-Force):
​
- Check all possible substring for palindrome
​
```
class Solution {
public:
int countSubstrings(string s) {
int result = 0;
for (int i = 0; i < s.size(); i++)
for (int j = i; j < s.size(); j++)
if (isSubString(s, i, j))
result++;
return result;
}
bool isSubString(string& s, int start, int end) {
while (start < end)
if (s[start++] != s[end--])
return false;
return true;
}
};
​
// TC: O(n^3)
// SC: O(1)
```
​
Solution 2:
​
-