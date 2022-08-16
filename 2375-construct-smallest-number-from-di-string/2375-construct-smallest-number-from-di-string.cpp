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

// TC: O(n)
// SC: O(1) except the output