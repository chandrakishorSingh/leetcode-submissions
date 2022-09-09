Solution 1:
​
- Just remember the position of characters when they are seen for the first time and then ensure they are exactly `distance` unit apart.
​
```
class Solution {
public:
bool checkDistances(string s, vector<int>& distance) {
unordered_map<char, int> lastIndex;
for (int i = 0; i < s.size(); i++) {
auto ch = s[i];
if (lastIndex.count(ch)) {
if ((abs(lastIndex[ch] - i) - 1) != distance[ch - 'a'])
return false;
} else {
lastIndex[ch] = i;
}
}
return true;
}
};
​
// TC: Θ(n)
// SC: O(n)
```