class Solution {
public:
    vector<int> getCharFreq(string& s) {
        vector<int> charFreq(26);
        for (auto ch: s)
            charFreq[ch - 'a']++;

        return charFreq;
    }    
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxCharFreq(26);
        for (auto& word2: words2) {
            auto charFreq = getCharFreq(word2);
            
            for (int i = 0; i < charFreq.size(); i++)
                maxCharFreq[i] = max(maxCharFreq[i], charFreq[i]);
        }
        
        vector<string> result;
        for (auto& word1: words1) {
            auto charFreq = getCharFreq(word1);
            
            bool flag = true;
            for (int i = 0; i < charFreq.size(); i++) {
                if (charFreq[i] < maxCharFreq[i]) {
                    flag = false;
                    break;
                }
            }
            
            if (flag)
                result.push_back(word1);
        }
        
        return result;
    }
};