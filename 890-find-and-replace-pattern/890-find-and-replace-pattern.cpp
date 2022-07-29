class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        
        for (auto& word: words) {
            map<char, char> patternToWordMap;
            map<char, char> wordToPatternMap;
            
            bool flag = true;
            for (int i = 0; i < word.size() && flag; i++) {
                if (
                    patternToWordMap.count(pattern[i]) && patternToWordMap[pattern[i]] != word[i] ||
                    wordToPatternMap.count(word[i]) && wordToPatternMap[word[i]] != pattern[i]
                   )
                    flag = false;
                
                patternToWordMap[pattern[i]] = word[i];
                wordToPatternMap[word[i]] = pattern[i];
            }
            
            if (flag)
                result.push_back(word);
        }
        
        return result;
    }
};