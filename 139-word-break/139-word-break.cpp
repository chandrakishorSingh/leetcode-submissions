class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        int m = s.size();
        
        vector<vector<int>> lastCharToWord(26, vector<int>());
        for (int i = 0; i < n; i++) {
            lastCharToWord[wordDict[i].back() - 'a'].push_back(i);
        }
        
        vector<int> store(m + 1, -1);
        store[0] = 1;
        
        return dfs(s, wordDict, m, lastCharToWord, store);
    }
    
    int dfs(string& s, vector<string>& wordDict, int size, vector<vector<int>>& lastCharToWord, vector<int>& store) {
        if (store[size] != -1)
            return store[size];
        
        bool result = false;
        for (auto index: lastCharToWord[s[size - 1] - 'a']) {
            if (isEndsWith(s, wordDict[index], size - 1)) {
                result |= dfs(s, wordDict, size - wordDict[index].size(), lastCharToWord, store);
                
                if (result)
                    break;
            }
        }
        
        store[size] = result;
        
        return store[size];
    }
    
    bool isEndsWith(string& s, string& other, int pos) {
        if (1 + pos < other.size())
            return false;
        
        int n = other.size();
        for (int i = 0; i < n; i++)
            if (s[pos - i] != other[n - 1 - i])
                return false;
        
        return true;
    }
};