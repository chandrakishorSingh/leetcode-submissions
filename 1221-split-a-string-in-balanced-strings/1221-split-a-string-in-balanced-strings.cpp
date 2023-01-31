class Solution {
public:
    int balancedStringSplit(string s) {
        int result = 0;
        
        int countL = 0;
        int countR = 0;
        for (auto ch: s) {
            if (ch == 'R') {
                countR++;
            } else {
                countL++;
            }
            
            if (countR == countL) {
                result++;
            }
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(n)