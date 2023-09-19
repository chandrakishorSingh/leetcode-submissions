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
        int width = (totalSum + target) / 2;
        vector<vector<int>> store(n + 1, vector<int>(width + 1));
        
        store[0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= width; j++) {
                int option1 = 0;
                if (nums[i - 1] <= j) {
                    option1 = store[i - 1][j - nums[i - 1]];
                }
                
                int option2 = store[i - 1][j];
                
                store[i][j] = option1 + option2;
            }
        }
        
        return store[n][width];
    }
};

// TC: O(n * sum(nums))
// SC: O(n * sum(nums))
