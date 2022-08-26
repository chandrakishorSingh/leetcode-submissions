class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> codeToAnagramGroup;
        
        for (auto& str: strs) {
            auto sortedString = string(str);
            sort(sortedString.begin(), sortedString.end());
            codeToAnagramGroup[sortedString].push_back(str);
        }
        
        vector<vector<string>> result;
        for (auto it = codeToAnagramGroup.begin(); it != codeToAnagramGroup.end(); it++) {
            result.push_back(it->second);
        }
        
        return result;
    }
};

// TC: O(n * k)
// SC: O(n), except the output