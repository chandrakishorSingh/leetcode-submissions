class Solution {
public:
    int subsetSum(vector<vector<int>>& store, vector<int>& nums, int target, int n) {
        if (target == 0) {
            return 1;
        }
        
        if (n == 0) {
            return 0;
        }
        
        if (store[n][target] != -1) {
            return store[n][target];
        }
        
        int option1 = 0;
        if (nums[n - 1] <= target) {
            option1 = subsetSum(store, nums, target - nums[n - 1], n - 1);
        }
        
        int option2 = subsetSum(store, nums, target, n - 1);
        
        store[n][target] = option1 || option2;
        return store[n][target];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if (sum % 2 == 1) {
            return false;
        }
        
        int n = nums.size();
        int target = sum / 2;
        vector<vector<int>> store(n + 1, vector<int>(target + 1, -1));
        
        return subsetSum(store, nums, target, n);
    }
};

// TC: O(n * sum(arr))
// SC: O(n * sum(arr))