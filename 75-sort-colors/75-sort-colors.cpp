class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroIndex = 0;
        int twoIndex = nums.size() - 1;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[index] == 0) {
                swap(nums[index++], nums[zeroIndex++]);
            } else if (nums[index] == 2) {
                swap(nums[index], nums[twoIndex--]);
            } else {
                index++;
            }
        }
    }
};

// TC: O(n)
// SC: O(1)