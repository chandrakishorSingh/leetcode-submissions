Solution 1:
​
- Observations
- Any substring of length k will represent a valid binary code.
- Only substring of length exactly k will represent a valid binary code.
- Substring of length k are linear. Exactly n - k - 1.
- The binary representation of all required codes represent 0, 1, 2, ..., 2^(k - 1)
​
- Hence, we can just run over the string in a window of size k and mark the numbers represented by that string as seen. We can use a simple array of size 2^k to mark those numbers.
- Also due to the way how binary number system(or any weighted number system for that matter) are represented, it's easy to get the next numbers as we move the window over the string.
​
```
class Solution {
public:
bool hasAllCodes(string s, int k) {
vector<int> nums((int)pow(2, k));
int n = s.size();
int start = 0;
int end = 0;
int num = 0;
for (; end < n; end++) {
num = num << 1;
num += s[end] == '1' ? 1: 0;
if (end >= k - 1) {
num = (num & (~(1 << k)));
start++;
}
if (end >= k - 1)
nums[num] = 1;
}
for (auto num: nums)
if (num == 0)
return false;
return true;
}
};
​
// TC: O(n)
// SC: O(2^k)
```
​