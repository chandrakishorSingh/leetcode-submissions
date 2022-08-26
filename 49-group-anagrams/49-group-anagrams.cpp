class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> codeToAnagramGroup;
        
        for (auto& str: strs) {
            auto code = encode(str);
            codeToAnagramGroup[code].push_back(str);
        }
        
        vector<vector<string>> result;
        for (auto it = codeToAnagramGroup.begin(); it != codeToAnagramGroup.end(); it++) {
            result.push_back(it->second);
        }
        
        return result;
    }
    
    string encode(string& str) {
        vector<int> freq(26);
        
        for (auto ch: str)
            freq[ch - 'a']++;
        
        string result;
        for (int i = 0; i < 26; i++)
            result += to_string(freq[i]) + " ";
        
        return result;
    }
};

// TC: O()