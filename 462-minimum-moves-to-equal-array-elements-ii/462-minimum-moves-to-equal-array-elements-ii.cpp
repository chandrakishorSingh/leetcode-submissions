class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        
        if (n % 2 == 1) {
            nth_element(nums.begin(), nums.begin() + (n / 2), nums.end());
            return offset(nums, nums[n / 2]);
        } else {
            nth_element(nums.begin(), nums.begin() + (n / 2), nums.end());
            int option1 = offset(nums, nums[n / 2]);
            
            nth_element(nums.begin(), nums.begin() + (n / 2) - 1, nums.end());
            int option2 = offset(nums, nums[(n / 2) - 1]);
            
            return min(option1, option2);
        }
    }
    
    int offset(vector<int>& nums, int value) {
        int result = 0;
        for (auto num: nums)
            result += abs(value - num);
        
        return result;
    }
};