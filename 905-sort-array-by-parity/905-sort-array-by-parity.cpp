class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        
        while (start <= end) {
            if (nums[start] & 1) {
                swap(nums[start], nums[end]);
                end--;
            } else {
                start++;
            }
        }
        
        return nums;
    }
};

// TC: O(n)
// SC: O(n)