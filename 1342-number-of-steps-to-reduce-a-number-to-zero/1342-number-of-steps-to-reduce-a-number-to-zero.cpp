class Solution {
public:
    int numberOfSteps(int num) {
        int result = 0;
        while (num != 0) {
            num = (num & 1) ? num - 1: num >> 1;
            result++;
        }
        
        return result;
    }
};

// TC: O(log(n))
// SC: O(1)