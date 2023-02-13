class Solution {
public:
    typedef long long ll;
    
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        
        ll result = 0;
        
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            int left = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int right = lower_bound(nums.begin() + i + 1, nums.end(), upper - nums[i] + 1) - nums.begin() - 1;
            
            result += right - left + 1;
        }
        
        return result;
    }
};

// TC: O(n * log(n))
// SC: O(sort())