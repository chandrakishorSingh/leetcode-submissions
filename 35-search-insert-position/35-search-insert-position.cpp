class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return _searchInsert(nums, 0, nums.size() - 1, target);
    }
    
    int _searchInsert(vector<int>& nums, int low, int high, int target) {
        if (low > high)
            return low;
        
        int mid = low + (high - low) / 2;
            
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target) {
            return _searchInsert(nums, low, mid - 1, target);
        } else {
            return _searchInsert(nums, mid + 1, high, target);
        }
    }
};

// TC: O(log(n))
// SC: O(1)