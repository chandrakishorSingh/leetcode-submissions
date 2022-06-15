Solution 1:
​
- Observe that a string of length `k` can only have a string of length `k - 1` as its previous element in the chain.
- Also for a string `s`, if there is a string `p` before it in some chain then `p` can be find out by deleting exactly one character from `s`.
- Hence, we can get the previous member in the chain for a given string by deleting one char at a time and seeing whether it's present in the `words` or not.
- We will sort the strings according to their length so that when we try to find the longest "tail" for current string, it will be present(as they will come before this string and hence will be processed first).
- I'm assuming that `unordered_map` uses `==` for comparison and it will take `O(l)` time for a string of length `l` to get compared using `==` operator.
​
```
class Solution {
public:
int longestStrChain(vector<string>& words) {
unordered_map<string, int> chainLength;
for (auto& word: words)
chainLength[word] = 1;
sort(words.begin(), words.end(), [](string& s1, string& s2) {
if (s1.size() < s2.size())
return true;
return false;
});
int result = 0;
for (auto& word: words) {
int maxChainLength = 0;
for (int i = 0; i < word.size(); i++) {
string prev = word.substr(0, i) + word.substr(i + 1);
if (chainLength.count(prev)) {
maxChainLength = max(maxChainLength, chainLength[prev]);
}
}
chainLength[word] = maxChainLength + 1;
result = max(result, maxChainLength + 1);
}
return result;
}
};
​
// TC: O(sum(len(words[i]) ^ 2)),
// SC: O(n * l), n = len(words), l = avg. length of string in words
```