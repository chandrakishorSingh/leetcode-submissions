class Solution {
public:
    int minimumPartition(string s, int k) {
        int result = 1;
        int64_t currentValue = 0;
        for (int i = 0; i < s.size(); i++) {
            currentValue = currentValue * 10 + (s[i] - '0');
            
            if (currentValue > k) {
                currentValue = s[i] - '0';
                result++;
            }
            
            if (currentValue > k) {
                result = -1;
                break;
            }
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(1)