class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n);
        
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            
            while (j > 0 && s[j] != s[i]) {
                j = lps[j - 1];
            }
            
            if (s[j] == s[i])
                j++;
            
            lps[i] = j;
        }
        
        return s.substr(0, lps[n - 1]);
    }
};

// TC: O(n)
// SC: O(n)