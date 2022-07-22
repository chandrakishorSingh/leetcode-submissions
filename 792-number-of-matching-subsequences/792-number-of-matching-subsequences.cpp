class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        vector<vector<int>> charToSubarray(26, vector<int>(n, -1));
        
        charToSubarray[s.back() - 'a'][n - 1] = n - 1;
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                charToSubarray[j][i] = charToSubarray[j][i + 1];
            }
            
            charToSubarray[s[i] - 'a'][i] = i;
        }
        
        int result = 0;
        for (auto& word: words)
            if (isSubSequenceOf(word, charToSubarray))
                result++;
        
        return result;
    }
    
    bool isSubSequenceOf(string& subSequence, vector<vector<int>>& charToSubarray) {
        bool result = true;
        int windowStartingIndex = 0;
        int n = charToSubarray[0].size();
        int m = subSequence.size();
        
        for (int i = 0; i < m; i++) {
            if (windowStartingIndex >= n) {
                result = false;
                break;
            }
                
            windowStartingIndex = charToSubarray[subSequence[i] - 'a'][windowStartingIndex];
            
            if (windowStartingIndex == -1) {
                result = false;
                break;
            }
            
            windowStartingIndex++;
        }
        
        return result;
    }
};

// TC: O(len(s) + sum(len(words[i])))
// SC: O(len(s))