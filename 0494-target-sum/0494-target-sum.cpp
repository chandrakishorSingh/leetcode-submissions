class Solution {
private:
    int countSubsetSum(vector<int>& nums, int target, int n) {
        if (n == 0) {
            return target == 0 ? 1 : 0;
        }
        
        int option1 = 0;
        if (nums[n - 1] <= target) {
            option1 = countSubsetSum(nums, target - nums[n - 1], n - 1);
        }
        
        int option2 = countSubsetSum(nums, target, n - 1);
        
        return option1 + option2;
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        target = abs(target);
        
        if ((totalSum + target) % 2 == 1 || target > totalSum) {
            return 0;
        }
        
        int n = nums.size();
        return countSubsetSum(nums, (totalSum + target) / 2, n);
    }
};

// TC: O(n * sum(nums))
// SC: O(n * sum(nums))
