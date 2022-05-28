class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        
        unordered_map<char, int> lastIndex;
        
        int start = 0;
        int end = 0;
        for (; end < s.size(); end++) {
            if (lastIndex.count(s[end])) {
                while (start <= lastIndex[s[end]])
                    lastIndex.erase(s[start++]);
            }
            
            lastIndex[s[end]] = end;
            
            result = max(result, end - start + 1);
        }
        
        return result;
    }
};