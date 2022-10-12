class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            int current;
            if ((nums[0] <= nums[mid]) == (nums[0] <= target)) {
                current = nums[mid];
            } else if (target < nums[0]) {
                current = INT_MIN;
            } else {
                current = INT_MAX;
            }
            
            if (current == target) {
                result = mid;
                break;
            } else if (current < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return result;
    }
};