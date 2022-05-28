class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        
        for (int i = 1; i <= nums.size(); i++) {
            result ^= i;
            result ^= nums[i - 1];
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(1)