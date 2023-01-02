class Solution {
public:
    int minimumPartition(string s, int k) {
        if (k <= 9) {
            int maxDigit = *max_element(s.begin(), s.end()) - '0';
            
            if (maxDigit > k)
                return -1;
        }
        
        int result = 1;
        int64_t currentValue = 0;
        for (int i = 0; i < s.size(); i++) {
            currentValue = currentValue * 10 + (s[i] - '0');
            
            if (currentValue > k) {
                currentValue = s[i] - '0';
                result++;
            }
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(1)