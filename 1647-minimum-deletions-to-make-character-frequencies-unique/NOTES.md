Solution 1:
​
- The freq. of every character can be visualized as points on a 1D number line.
- If no two points coincide then no need to delete the characters.
- Otherwise we have to move some of the points to the left(as characters can only be deleted and can't be increased).
- It's easy to see that we should move the points to left by one unit at a time and should stop as soon as we reach at a point which is not occupied by any character.
- We need to have an efficient lookup structure for querying whether some point is occupied by some character or not. So, I'm using a `unordered_set` here.
- Worst case will happen when the freq. of all characters are same.
​
```
class Solution {
public:
int minDeletions(string s) {
vector<int> freq(26);
for (auto ch: s)
freq[ch - 'a']++;
unordered_set<int> st;
int result = 0;
for (auto num: freq) {
if (num == 0)
continue;
if (st.count(num)) {
while (num != 0 && st.count(num)) {
num--;
result++;
}
if (num != 0)
st.insert(num);
} else {
st.insert(num);
}
}
return result;
}
};
​
// TC: O(n + k^2)
// SC: O(k)
// k = # of unique characters in the string
```