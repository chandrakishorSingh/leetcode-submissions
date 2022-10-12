class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                
                if (nums[i] == 0 || nums[j] == 0)
                    continue;
                
                auto left = lower_bound(nums.begin(), nums.end(), nums[j] - nums[i] + 1);
                auto right = upper_bound(nums.begin(), nums.end(), nums[j] + nums[i] - 1) - 1;
                
                int count = right - left;
                
                if (left <= nums.begin() + i && count > 0)
                    count--;
                
                result += count;
            }
        }
        
        return result / 3;
    }
};

// TC: O(n^2 * log(n))
// SC: SC of lower_bound() and upper_bound() or O(1)