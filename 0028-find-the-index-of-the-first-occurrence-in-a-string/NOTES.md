Solution 1(Brute-Force):
​
- Compare the given `needle` with every string starting from each index of `haystack`.
​
```
class Solution {
public:
int strStr(string haystack, string needle) {
auto index = haystack.find(needle);
return index == string::npos ? -1 : index;
}
};
​
// TC: O(m * n), m, n = lengths of given two strings
// SC: O(1)
```