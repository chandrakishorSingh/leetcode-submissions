class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        vector<int> lps(n);
        
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            
            while (j > 0 && needle[j] != needle[i]) {
                j = lps[j - 1];
            }
            
            if (needle[j] == needle[i]) {
                j++;
            }
            
            lps[i] = j;
        }
        
        int m = haystack.size();
        int index = -1;
        int j = 0;
        for (int i = 0; i < m; i++) {
            while (j > 0 && needle[j] != haystack[i]) {
                j = lps[j - 1];
            }
            
            if (needle[j] == haystack[i]) {
                j++;
                
                if (j == n) {
                    index = i - n + 1;
                    break;
                }
            }
        }
        
        return index;
    }
};

// TC: O(m * n), m, n = lengths of given two strings
// SC: O(1)