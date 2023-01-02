Solution 1:
​
- At first, it seems to be a greedy problem. And it really is.
- I don't have a rigorous proof. But intuition says that there is no reason why the next digit should not be included in the current "window" when it can be included. This is because if we start a new "window" for this next digit then we have used one extra "window". This could have been avoided if would have included the next digit in the previous "window". Remember that the "space" left in the previous "window" can't be used by the next "windows".
- So there is no point in wasting any "space".
​
```
class Solution {
public:
int minimumPartition(string s, int k) {
if (k <= 9) {
int maxDigit = *max_element(s.begin(), s.end()) - '0';
if (maxDigit > k)
return -1;
}
int result = 1;
int64_t currentValue = 0;
for (int i = 0; i < s.size(); i++) {
currentValue = currentValue * 10 + (s[i] - '0');
if (currentValue > k) {
currentValue = s[i] - '0';
result++;
}
}
return result;
}
};
​
// TC: O(n)
// SC: O(1)
```