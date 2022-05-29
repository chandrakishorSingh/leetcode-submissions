class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!hasCommonChars(words[i], words[j]))
                    result = max(result, (int)words[i].size() * (int)words[j].size());
            }
        }
        
        return result;
    }
    
    bool hasCommonChars(string& str1, string& str2) {
        vector<int> alphabets1(26);
        for (auto ch: str1)
            alphabets1[ch - 'a'] = 1;
        
        vector<int> alphabets2(26);
        for (auto ch: str2)
            alphabets2[ch - 'a'] = 1;
        
        for (int i = 0; i < 26; i++)
            if ((alphabets1[i]) && (alphabets2[i]))
                return true;
        
        return false;
    }
};