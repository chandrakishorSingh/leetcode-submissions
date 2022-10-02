Solution 1(Brute-Force):
​
- For every character, just reduce the freq. of each of the character once and check if all freq. are now equal or not.
​
```
class Solution {
public:
bool equalFrequency(string word) {
vector<int> freq(26);
for (auto ch: word)
freq[ch - 'a']++;
bool result = false;
for (int i = 0; i < freq.size(); i++) {
if (freq[i] == 0)
continue;
freq[i]--;
if (isFreqSame(freq)) {
result = true;
break;
}
freq[i]++;
}
return result;
}