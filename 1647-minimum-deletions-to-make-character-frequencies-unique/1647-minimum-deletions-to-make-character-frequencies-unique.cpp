class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        for (auto ch: s)
            freq[ch - 'a']++;

        sort(freq.begin(), freq.end());
        
        int maxFreqAllowed = INT_MAX;
        int result = 0;
        for (int i = freq.size() - 1; i >= 0; i--) {
            if (freq[i] == 0)
                break;
            
            if (freq[i] > maxFreqAllowed) {
                result += freq[i] - maxFreqAllowed;
                maxFreqAllowed = max(0, maxFreqAllowed - 1);
            } else {
                maxFreqAllowed = freq[i] - 1;
            }
        }
        
        return result;
    }
};

// TC: O(n + k^2 * log(k))
// SC: O(k)