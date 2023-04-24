class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return result;
    }
};

// TC: O(log(n))
// SC: O(1)