class Solution {
public:
    string largestGoodInteger(string num) {
        int count = 1;
        char result = -1;
        
        for (int i = 1; i < num.size(); i++) {
            if (num[i] == num[i - 1]) {
                count++;
                
                if (count == 3) {
                    result = max(result, num[i]);
                    count = 0;
                }
            } else {
                count = 1;
            }
        }
        
        return result == -1 ? "" : string(3, result);
    }
};

// TC: O(n)
// SC: O(1)