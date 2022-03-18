class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        int productFromRight = 1;
        int productFromLeft = 1;
        for (int i = 0; i < n; i++) {
            result[i] *= productFromLeft;
            result[n - 1 - i] *= productFromRight;
            
            productFromLeft *= nums[i];
            productFromRight *= nums[n - 1 - i];
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(1)