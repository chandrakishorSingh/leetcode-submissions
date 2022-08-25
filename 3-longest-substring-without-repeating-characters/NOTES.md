break;
​
st.insert(s[j]);
result = max(result, j - i + 1);
}
}
return result;
}
};
​
// TC: O(n^2)
// SC: O(1)
```
​
Solution 4:
​
- Similar to 1st solution.
- The only difference is that here the start pointer is not made to traverse to the previously found duplicate position by moving one position at a time. Instead it directly jumps to the required position.
- We store the last position of each of the characters. This helps in finding whether the currently encountered character is a duplicate or not(by examining whether it's last position lies between the current start and end).
​
```
class Solution {
public:
int lengthOfLongestSubstring(string s) {
unordered_map<char, int> lastCharacterPos;
int start = 0;
int result = 0;
for (int end = 0; end < s.size(); end++) {
if (lastCharacterPos.count(s[end]) && lastCharacterPos[s[end]] >= start) {
start = lastCharacterPos[s[end]] + 1;
}
lastCharacterPos[s[end]] = end;
result = max(result, end - start + 1);
}
return result;
}
};
​
// TC: Θ(n)
// SC: O(# of unique characters in s)
```