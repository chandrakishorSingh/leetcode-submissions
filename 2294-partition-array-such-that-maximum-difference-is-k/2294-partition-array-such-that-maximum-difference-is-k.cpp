class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int result = 1;
        int anchor = nums[0];
        for (auto num: nums) {
            if (num - anchor <= k)
                continue;
            
            anchor = num;
            result++;
        }
        
        return result;
    }
};

// TC: O(n * log(n))
// SC: O(1)