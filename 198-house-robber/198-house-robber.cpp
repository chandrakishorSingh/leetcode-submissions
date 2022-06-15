class Solution {
public:
    int rob(vector<int>& nums) {
        int option1 = 0;
        int option2 = nums[0];
        
        int result = option2;
        for (int i = 1; i < nums.size(); i++) {
            result = max(nums[i] + option1, option2);
            
            option1 = option2;
            option2 = result;
        }
        
        return result;        
    }
};

// TC: O(2^n)
// SC: O(n)