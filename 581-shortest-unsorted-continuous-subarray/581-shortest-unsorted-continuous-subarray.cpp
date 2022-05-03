class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> smallestFromRight(n, nums[n - 1]);
        vector<int> largestFromLeft(n, nums[0]);
        
        for (int i = n - 2; i >= 0; i--)
            smallestFromRight[i] = min(nums[i], smallestFromRight[i + 1]);
        
        for (int i = 1; i < n; i++)
            largestFromLeft[i] = max(nums[i], largestFromLeft[i - 1]);
        
        int start = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > smallestFromRight[i]) {
                start = i;
                break;
            }
        }
        
        if (start == -1)
            return 0;
        
        int end = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < largestFromLeft[i]) {
                end = i;
                break;
            }
        }
        
        return end - start + 1;
    }
};

// TC: O(n*log(n))
// SC: O(n)