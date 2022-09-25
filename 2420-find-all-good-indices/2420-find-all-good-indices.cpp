class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        
        int count = 0;
        vector<int> prefix(n);
        for (int i = 1; i < n; i++) {
            count = nums[i] <= nums[i - 1] ? count + 1: 0;
            prefix[i] = count;
        }
        
        count = 0;
        vector<int> suffix(n);
        for (int i = n - 2; i >= 0; i--) {
            count = nums[i] <= nums[i + 1] ? count + 1: 0;
            suffix[i] = count;
        }
        
        vector<int> result;
        for (int i = k; i < n - k; i++) {
            if ((prefix[i - 1] >= k - 1) and (suffix[i + 1] >= k - 1))
                result.push_back(i);
        }
        
        return result;
    }
};