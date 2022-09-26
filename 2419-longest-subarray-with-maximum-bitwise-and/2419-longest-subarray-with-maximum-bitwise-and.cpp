class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        
        int result = 1;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxElement) {
                count++;
            } else {
                count = 0;
            }
            
            result = max(result, count);
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(1)