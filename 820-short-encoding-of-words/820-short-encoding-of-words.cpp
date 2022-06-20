class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for (auto& word: words)
            reverse(word.begin(), word.end());
        
        sort(words.begin(), words.end());
        
        int n = words.size();
        int result = words[0].size() + 1;
        for (int i = 1; i < n; i++) {
            if (startsWith(words[i], words[i - 1])) {
                result += words[i].size() - words[i - 1].size();
                continue;
            }
            
            result += words[i].size() + 1;
        }
        
        return result;
    }
    
    bool startsWith(string& s, string& prefix) {
        if (prefix.size() > s.size())
            return false;
            
        for (int i = 0; i < prefix.size(); i++)
            if (prefix[i] != s[i])
                return false;
                
        return true;
    }
};