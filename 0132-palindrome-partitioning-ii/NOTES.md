Solution 1:
​
```
class Solution {
private:
bool _isPalindrome(string& s, int left, int right) {
while (left < right) {
if (s[left] != s[right]) {
return false;
}
left++;
right--;
}
return true;
}
int _minCut(string& s, int left, int right) {
if (_isPalindrome(s, left, right)) {
return 0;
}
int result = right - left;
for (int i = left; i < right; i++) {
if (_isPalindrome(s, left, i)) {
result = min(result, 1 + _minCut(s, i + 1, right));
}
}
return result;
}
public:
int minCut(string s) {
int n = s.size();
return _minCut(s, 0, n - 1);
}
};
​
// TC: ?
// SC: O(len(s))
```