Solution 1(Stack overflow):
​
- Recursive approach.
- It's easy to see that this problem is of MCM type. As, we are required to put an "operator"(the break-or-swap operation) between every two "operands"(the characters of string) and figure out the sequence of performing these operations so that the corresponding result is the required result.
- The logic is quite simple. Given the string s1, we will place one operator between any two successive characters assuming that this operation will be performed at the end. Then the two partitions of the string will be compared with the corresponding partitions of the string s2. Precisely speaking, the left partition of the string s1 will be compared with the left partition of the string s2 and similarly for the right partition. And after that the left partition of the string s1 will be compared with the right partition of string s2 and vice versa.
​
```
class Solution {
private:
bool _mcm(string& s1, string& s2, int left1, int right1, int left2, int right2) {
if (right1 - left1 != right2 - left2) {
return false;
}
if (left1 == right1) {
return s1[left1] == s2[left2];
}
bool result = false;
int limit = right1 - left1;
for (int i = 0; i < limit; i++) {
if (result) {
break;
}
bool option1 = _mcm(s1, s2, left1, left1 + i, left2, left2 + i, store) & _mcm(s1, s2, left1 + i + 1, right1, left2 + i + 1, right2, store);
bool option2 = _mcm(s1, s2, left1, left1 + i, right2 - i, right2, store) & _mcm(s1, s2, left1 + i + 1, right1, left2, right2 - i - 1, store);
result = option1 | option2;
}
return result;
}
public:
bool isScramble(string s1, string s2) {
int n = s1.size();
return _mcm(s1, s2, 0, n - 1, 0, n - 1);
}
};
```
​
Solution 2:
​
- Recursive approach with memoization.
​
```
class Solution {
private:
typedef vector<vector<vector<vector<int>>>> fourDimentionalVector;
bool _mcm(string& s1, string& s2, int left1, int right1, int left2, int right2, fourDimentionalVector& store) {
if (right1 - left1 != right2 - left2) {
return false;
}
if (left1 == right1) {
return s1[left1] == s2[left2];
}
bool result = false;
int limit = right1 - left1;
for (int i = 0; i < limit; i++) {
if (result) {