class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            int maxLength = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    maxLength = max(maxLength, dp[j]);
                }
            }
            
            dp[i] = maxLength + 1;
            
            result = max(result, dp[i]);
        }
        
        return result;
    }
};

// TC: O(2^n)
// SC: O(n)