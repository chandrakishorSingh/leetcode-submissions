class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sequence(nums.size());
        int maxSequenceLength = 0;
        
        for (auto num: nums) {
            auto pos = binarySearch(sequence, maxSequenceLength, num);
            sequence[pos] = num;
            
            maxSequenceLength = max(maxSequenceLength, pos + 1);
        }
        
        return maxSequenceLength;
    }
    
    int binarySearch(vector<int>& sequence, int size, int num) {
        int low = 0;
        int high = size - 1;
        
        int result = size;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (sequence[mid] >= num) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
};

// TC: O(n^2)
// SC: O(n)