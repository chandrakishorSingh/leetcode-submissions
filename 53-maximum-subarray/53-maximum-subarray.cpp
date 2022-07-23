class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int current = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            current = max(current + nums[i], nums[i]);
            result = max(result, current);
        }
        
        return result;
    }
};