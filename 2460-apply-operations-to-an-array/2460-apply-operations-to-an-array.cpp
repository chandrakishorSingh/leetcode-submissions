class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                continue;
            }
            
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
        
        vector<int> result;
        for (auto num: nums)
            if (num != 0)
                result.push_back(num);
        
        result.resize(n, 0);
        
        return result;
    }
};

// TC: O(n)
// SC: O(n)