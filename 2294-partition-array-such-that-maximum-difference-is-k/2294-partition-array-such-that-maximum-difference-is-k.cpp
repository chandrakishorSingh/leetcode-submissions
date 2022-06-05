class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int result = 1;
        int anchor = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - anchor <= k)
                continue;
            
            anchor = nums[i];
            result++;
        }
        
        return result;
    }
};