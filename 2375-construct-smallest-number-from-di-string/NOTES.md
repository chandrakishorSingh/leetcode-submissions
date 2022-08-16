Solution 1:
​
- Observations
- Forming a lexicographically smallest sequence from a given set of elements is a greedy method.
- Because, as we move from left to right, we want to place the current "smallest" possible element in the current position.
- Also, let's try to solve a simple version of the problem to get better understanding.
- When `pattern`  has only `I` then, the answer is just `123...n+1` if the length of the `pattern` is n.
- Similarly, when the pattern has only `D` then the answer is simply `n+1...321` if the `pattern` length is n.
- Therefore, it's intutive to see the characters of the `pattern` as blocks of `I`s and `D`s instead of single characters. And we know what should be the answer for each of those blocks.
- After these observations, it's easier to come up with the following implementation approach.
- For `pattern` of length n, generate the string `"123...n+1"`
- For every block of `D` just reverse the corresponding segment of generated string.
- Though this is not a rigorous proof, I think it's enough to convince that it could be correct.
​
```
class Solution {
public:
string smallestNumber(string pattern) {
int n = pattern.size();
string result = "1";
for (int i = 1; i <= n; i++)
result += to_string(i + 1);
int start = 0;
int i = 1;
while (i <= n) {
if (pattern[i - 1] == 'I') {
start = i;
i++;
continue;
}
while (i <= n && pattern[i] == 'D') {
i++;
}
reverse(result.begin() + start, result.begin() + i + 1);
i++;
}
return result;
}
};
​
// TC: O(n)
// SC: O(1) except the output
```