class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        vector<int> suffixSum(n + 1);
        for (int i = n - 1; i >= 0; i--)
            suffixSum[i] += suffixSum[i + 1] + nums[i];
        
        int result = INT_MAX;
        int prefixSum = 0;
        for (int i = 0; i <= n; i++) {
            prefixSum += i > 0 ? nums[i - 1] : 0;
            
            int low = i;
            int high = n;
            int index = binarySearch(low, high, x - prefixSum, suffixSum);
            
            if (index != -1)
                result = min(result, i + n - index);
        }
        
        return result == INT_MAX ? -1: result;
    }
    
    int binarySearch(int low, int high, int target, vector<int>& arr) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] == target)
                return mid;
            else if (arr[mid] < target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        return -1;
    }
};

// TC: O(n) on average
// SC: O(n)