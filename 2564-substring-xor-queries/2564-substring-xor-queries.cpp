class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> substrings;
        
        for (int i = 0; i < s.size(); i++) {
            int value = 0;
            int limit = min((int)s.size() - 1, i + 30);

            for (int j = i; j <= limit; j++) {
                value = (value << 1) + (s[j] - '0');
                
                auto it = substrings.find(value);
                if (it == substrings.end()) {
                    substrings[value] = {i, j};
                } else {
                    int oldRange = it->second[1] - it->second[0];
                    int newRange = j - i;
                    
                    if (newRange < oldRange) {
                        it->second = {i, j};
                    }
                }
            }
        }
        
        vector<vector<int>> result;
        for (auto& query: queries) {
            auto it = substrings.find(query[0] ^ query[1]);
            
            if (it == substrings.end()) {
                result.push_back({-1, -1});
            } else {
                result.push_back(it->second);
            }
        }
        
        return result;
    }
};

// TC: O()
// SC: O(n)