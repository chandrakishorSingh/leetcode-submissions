class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> freq(26);
        for (auto ch: word)
            freq[ch - 'a']++;
        
        bool result = false;
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] == 0)
                continue;
            
            freq[i]--;
            
            if (isFreqSame(freq)) {
                result = true;
                break;
            }
            
            freq[i]++;
        }
        
        return result;
    }
    
    bool isFreqSame(vector<int>& freq) {
        int prev = -1;
        for (auto num: freq) {
            if (num == 0)
                continue;
            
            if (prev == -1) {
                prev = num;
                continue;
            }
            
            if (prev != num) {
                return false;
            }
        }
        
        return true;
    }
};
