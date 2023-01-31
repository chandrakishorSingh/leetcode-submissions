Solution 1:
​
- It's easy to see that it can be solved using a stack.
​
```
class Solution {
public:
int balancedStringSplit(string s) {
int result = 0;
stack<char> st;
for (auto ch: s) {
if (st.empty()) {
st.push(ch);
continue;
}
if (st.top() != ch) {
st.pop();
} else {
st.push(ch);
}
if (st.empty()) {
result++;
}