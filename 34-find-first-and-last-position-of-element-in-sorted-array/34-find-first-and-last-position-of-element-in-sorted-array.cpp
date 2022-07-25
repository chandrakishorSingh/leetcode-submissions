class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto firstPosition = binarySearch(nums, target, true);
        auto lastPosition = binarySearch(nums, target, false);
        
        return {firstPosition, lastPosition};
    }
    
    int binarySearch(vector<int>& nums, int target, bool isLeft) {
        int low = 0;
        int high = nums.size() - 1;
        
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                result = mid;
                
                if (isLeft)
                    high = mid - 1;
                else
                    low = mid + 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return result;
    }
};