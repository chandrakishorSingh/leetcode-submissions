Solution 1:
​
- The main observation here is that it doesn't matter in which order one do "k removals", the final string is going to be same.
- So, we will do k-removals in a greedy manner. As soon as we see k consecutive same chars, we will remove them.
- A stack is used to implement this idea. As it is cheap to remove the chars if we found them to be in a k-removal substring.
- Every char is pushed into the stack once and they may be removed from the stack at most once. Hence, time and space complexity is linear.
​
```
class Solution {
public:
string removeDuplicates(string s, int k) {
stack<pair<char, int>> st;
for (auto ch: s) {
if (!st.empty() && st.top().first == ch) {
st.push({ ch, st.top().second + 1 });
} else {
st.push({ch, 1});
}
if (!st.empty() && st.top().second == k) {
for (int i = 0; i < k; i++)
st.pop();
}
}
string result = "";
while (!st.empty()) {
result += st.top().first;
st.pop();
}
reverse(result.begin(), result.end());
return result;
}
};
​
// TC: O(n)
// SC: O(n)
```