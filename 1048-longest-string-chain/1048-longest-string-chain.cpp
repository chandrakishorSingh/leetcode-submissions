class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> chainLength;
        for (auto& word: words)
            chainLength[word] = 1;
        
        sort(words.begin(), words.end(), [](string& s1, string& s2) {
            if (s1.size() < s2.size())
                return true;
            return false;
        });
        
        int result = 0;
        for (auto& word: words) {
            int maxChainLength = 0;
            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                
                if (chainLength.count(prev)) {
                    maxChainLength = max(maxChainLength, chainLength[prev]);
                }
            }
            
            chainLength[word] = maxChainLength + 1;
            
            result = max(result, maxChainLength + 1);
        }
        
        return result;
    }
};

// TC: O()