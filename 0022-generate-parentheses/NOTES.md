TODO:
​
- The number of such possible strings is equal to corresponding catalan number as written in discuss section. Learn about these numbers.
​
Solution 1:
​
- Backtracking approach.
- We need to choose 2n characters. Each of which can only be from '(' or ')'. Also, we need to ensure that the resulting string is balanced in terms of parentheses.
- So, for each of the position, we consider both of the characters(taking one at a time) and proceed forward ensuring that the current partial solution string have the "chance" of becoming balanced in future(this is done by `isParenthesesBalanced` variable).
​
```
class Solution {
private:
void backtrack(int n, string& s, int isParenthesesBalanced, vector<string>& result) {
if (n == 0) {
if (isParenthesesBalanced == 0) {
result.push_back(s);
}
return;
}
if (isParenthesesBalanced < 0) {
return;
}