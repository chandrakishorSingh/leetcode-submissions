class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefix(len), suffix(len);
        
        prefix[0] = 1;
        suffix[len - 1] = 1;
        for (int i = 1; i <= len - 1; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            suffix[len - i - 1] = suffix[len - i] * nums[len - i];
        }
        
        vector<int> product(len);
        for (int i = 0; i < len; i++) {
            product[i] = prefix[i] * suffix[i];
        }
        
        return product;
    }
};

// TC: O(n)
// SC: O(n)