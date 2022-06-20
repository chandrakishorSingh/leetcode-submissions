Solution 1:
​
- One way to arrange(or encode) the strings is to just add a '#' at the end of every string and concatenate them together.
- Observe that the only way this length can be reduced is when a string is a suffix of another.
- Hence, we just need to find whether, for a given string, a string with this string as suffix exists or not.
- Since, we have to align strings from the end, we will reverse all the strings and then we will sort them. Then all the strings which can be the suffix of some other strings will come side by side. Now, it will become very easy to find them.
​
```
class Solution {
public:
int minimumLengthEncoding(vector<string>& words) {
for (auto& word: words)
reverse(word.begin(), word.end());
sort(words.begin(), words.end());
int n = words.size();
int result = words[0].size() + 1;
for (int i = 1; i < n; i++) {
if (startsWith(words[i], words[i - 1])) {
result += words[i].size() - words[i - 1].size();