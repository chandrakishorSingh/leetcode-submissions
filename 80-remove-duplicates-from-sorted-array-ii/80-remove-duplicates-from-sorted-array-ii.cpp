class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int result = 1;
        
        int n = nums.size();
        int i = 1;
        int j = 0;
        while (i < n) {
            if (nums[i] == nums[j]) {
                swap(nums[i++], nums[++j]);
                result++;
            }
            
            while (i < n && nums[i] == nums[j])
                i++;
            
            if (i == n)
                break;
            
            swap(nums[i++], nums[++j]);

            result++;
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(1)