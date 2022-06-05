class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int result = 1;
        int prev = nums[0];
        for (auto num: nums) {
            if (num - prev <= k)
                continue;
            
            prev = num;
            result++;
        }
        
        return result;
    }
};

// TC: O(n * log(n))
// SC: O(1)