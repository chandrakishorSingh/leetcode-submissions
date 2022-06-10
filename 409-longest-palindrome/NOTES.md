Solution 1:
​
- Count the number of pairs of characters `pairs`.
- If some characters can't form a pair then we can create odd length palindrome.
​
```
class Solution {
public:
int longestPalindrome(string s) {
map<char, int> freq;
for (auto ch: s)
freq[ch]++;
int pairs = 0;
for (auto it = freq.begin(); it != freq.end(); it++)
pairs += it->second / 2;
return pairs * 2 == s.size() ? pairs * 2 : pairs * 2 + 1;
}
};
​
// TC: O(n * log(n))
// SC: O(n)
```