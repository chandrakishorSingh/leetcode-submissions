class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        
        // -1: null, 0: hill, 1: valley
        int status = -1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                if (status == -1) {
                    status = 0;
                } else if (status == 1) {
                    status = 0;
                    count++;
                }
            } else if (nums[i] > nums[i + 1]) {
                if (status == -1) {
                    status = 1;
                } else if (status == 0) {
                    status = 1;
                    count++;
                }
            }
        }
        
        return count;
    }
};

// TC: O(n)
// SC: O(1)