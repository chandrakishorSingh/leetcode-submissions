class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> freq;
        
        for (auto ch: s)
            freq[ch]++;
        
        int result = 0;
        for (auto it = freq.begin(); it != freq.end(); it++)
            result += it->second / 2;
        
        return result * 2 == s.size() ? result * 2 : result * 2 + 1;
    }
};