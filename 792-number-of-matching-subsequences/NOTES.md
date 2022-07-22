​
Solution 1:
​
- It's possible to check whether a given string `sub` is a subsequence of other string `s` in linear time O(len(s)).
- So, we can have a quadratic time algorithm easily.
​
```
class Solution {
public:
int numMatchingSubseq(string s, vector<string>& words) {
int result = 0;
for (auto& word: words)
if (isSubSequenceOf(word, s))
result++;
return result;
}
bool isSubSequenceOf(string s, string t) {
int index = 0;
for (int i = 0; i < t.size() && index < s.size(); i++) {
if (t[i] == s[index])
index++;
}
return index == s.size();
}
};
// TC: O(len(s) * len(words))
// SC: O(1)
```
​
Solution 2:
​
- This approach is similar to above one.
- Here, we are storing the indices of the first occurrence of all characters which are at the right of current character at each of the index positions.
- A 2D array of size 26 x n is used to store the info.
- This way, for every given word, we go to the largest possible window of substring of s for finding the existence of the subsequence.
- P.S.: Though it's not the best solution, I'm glad that I was able to come up with this solution on my own.
​
```
class Solution {
public:
int numMatchingSubseq(string& s, vector<string>& words) {
int n = s.size();
vector<vector<int>> charToSubarray(26, vector<int>(n, -1));
charToSubarray[s.back() - 'a'][n - 1] = n - 1;
for (int i = n - 2; i >= 0; i--) {
for (int j = 0; j < 26; j++) {
charToSubarray[j][i] = charToSubarray[j][i + 1];
}
charToSubarray[s[i] - 'a'][i] = i;
}