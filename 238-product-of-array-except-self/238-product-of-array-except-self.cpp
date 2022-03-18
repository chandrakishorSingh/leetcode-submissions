class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        
        for (int i = 1; i < n; i++) {
            nums[i - 1] = nums[i];
        }
        nums[n - 1] = 1;
        
        for (int i = n - 2; i >= 0; i--) {
            nums[i] = nums[i] * nums[i + 1];
        }
        
        for (int i = 0; i < n; i++) {
            result[i] = result[i] * nums[i];
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(n)