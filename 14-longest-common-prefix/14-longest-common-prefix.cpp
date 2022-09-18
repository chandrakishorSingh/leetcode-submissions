class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int length = strs[0].size();
        
        for (int i = 1; i < strs.size(); i++) {
            for (int j = 0; j < min((int)strs[i].size(), length); j++) {
                if (strs[0][j] != strs[i][j]) {
                    length = j;
                    break;
                }
            }
            
            length = min(length, (int)strs[i].size());
        }
        
        return strs[0].substr(0, length);
    }
};