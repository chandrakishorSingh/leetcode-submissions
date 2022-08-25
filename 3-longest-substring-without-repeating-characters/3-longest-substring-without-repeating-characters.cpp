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