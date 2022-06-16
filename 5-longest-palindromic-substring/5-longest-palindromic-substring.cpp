class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        string result = extendPalindrome(s, n - 1, n - 1);
        for (int i = 0; i < n - 1; i++) {
            auto oddPalindrome = extendPalindrome(s, i, i);
            auto evenPalindrome = extendPalindrome(s, i, i + 1);
            
            if (oddPalindrome.size() > result.size())
                result = oddPalindrome;
            
            if (evenPalindrome.size() > result.size())
                result = evenPalindrome;
        }
        
        return result;
    }
    
    string extendPalindrome(string& s, int start, int end) {
        while (start >= 0 && end < s.size() && s[start] == s[end]) {
            start--;
            end++;
        }
        
        return s.substr(start + 1, end - start - 1);
    }
};