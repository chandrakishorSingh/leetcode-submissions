class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        target = abs(target);
        
        if ((totalSum + target) % 2 == 1 || target > totalSum) {
            return 0;
        }
        
        int n = nums.size();
        int width = (totalSum + target) / 2;
        vector<int> store(width + 1);
        
        store[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = width; j >= 0; j--) {
                int option1 = 0;
                if (nums[i - 1] <= j) {
                    option1 = store[j - nums[i - 1]];
                }
                
                int option2 = store[j];
                
                store[j] = option1 + option2;
            }
        }
        
        return store[width];
    }
};

// TC: O(n * sum(nums))
// SC: O(n * sum(nums))
