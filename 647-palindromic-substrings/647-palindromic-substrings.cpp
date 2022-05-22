class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++)
            for (int j = i; j < s.size(); j++)
                if (isSubString(s, i, j))
                    result++;
                
        return result;
    }
    
    bool isSubString(string& s, int start, int end) {
        while (start < end)
            if (s[start++] != s[end--])
                return false;
        
        return true;
    }
};