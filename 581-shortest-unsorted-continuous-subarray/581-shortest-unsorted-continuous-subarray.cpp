class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy(nums.begin(), nums.end());
        
        sort(copy.begin(), copy.end());
        
        int start = -1;
        int end = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (copy[i] != nums[i]) {
                start = i;
                break;
            }
        }
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] != copy[i]) {
                end = i;
                break;
            }
        }
        
        if (start == -1)
            return 0;
        
        return end - start + 1;
    }
};