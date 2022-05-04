class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1;
        int smallestSoFar = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            smallestSoFar = min(smallestSoFar, nums[i]);
            
            if (nums[i] != smallestSoFar) {
                start = i;
            }
        }
        
        if (start == -1)
            return 0;
        
        int largestSoFar = nums[0];
        int end;
        for (int i = 1; i < n; i++) {
            largestSoFar = max(largestSoFar, nums[i]);
            
            if (nums[i] != largestSoFar)
                end = i;
        }
        
        return end - start + 1;
    }
};

// TC: O(n)
// SC: O(n)