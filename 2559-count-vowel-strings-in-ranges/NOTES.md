Solution 1:
​
- Since queries are applied on a static array(array doesn't change between two queries), we can use prefix sum to answer each queries.
​
```
class Solution {
public:
vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
set<char> st(vowels.begin(), vowels.end());
int n = words.size();
vector<int> stringKind(n);
for (int i = 0; i < words.size(); i++) {
if (st.count(words[i].front()) && st.count(words[i].back())) {
stringKind[i] = 1;
}
}
vector<int> prefixSum(n + 1);
for (int i = 1; i <= n; i++) {
prefixSum[i] += prefixSum[i - 1] + stringKind[i - 1];
}