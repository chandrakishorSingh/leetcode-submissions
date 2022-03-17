class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int evenIndex = 0;
        int oddIndex = 1;
        
        while (evenIndex < nums.size()) {
            if (nums[evenIndex] % 2 == 1) {
                swap(nums[evenIndex], nums[oddIndex]);
                
                oddIndex += 2;
            } else {
                evenIndex += 2;
            }
        }
        
        return nums;
    }
};

// TC: O(n)
// SC: O(1)