class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        
        for (auto ch: s)
            freq[ch]++;
        
        int pairs = 0;
        for (auto it = freq.begin(); it != freq.end(); it++)
            pairs += it->second / 2;
        
        return pairs * 2 == s.size() ? pairs * 2 : pairs * 2 + 1;
    }
};

// TC: O(n * log(n))
// SC: O(n)