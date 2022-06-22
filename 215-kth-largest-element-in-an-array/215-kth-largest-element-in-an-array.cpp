class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        random_shuffle(nums.begin(), nums.end());
        
        int n = nums.size();
        int targetIndex = n - k;
        int low = 0;
        int high = n - 1;
        int partitionIndex;
        while (true) {
            partitionIndex = partition(nums, low, high);
            if (partitionIndex == targetIndex)
                break;
            
            if (partitionIndex < targetIndex)
                low = partitionIndex + 1;
            else
                high = partitionIndex - 1;
        }
        
        return nums[targetIndex];
    }
    
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        
        int left = low + 1;
        int right = high;
        while (left <= right) {
            if (nums[left] <= pivot) {
                left++;
            } else {
                swap(nums[left], nums[right]);
                right--;
            }
        }
        
        swap(nums[low], nums[left - 1]);
        
        return left - 1;
    }
};