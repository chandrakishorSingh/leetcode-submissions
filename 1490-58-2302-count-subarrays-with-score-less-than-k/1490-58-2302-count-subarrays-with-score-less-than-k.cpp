class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long result = 0;
        
        int start = 0;
        long long sum = 0;
        for (int end = 0; end < nums.size(); end++) {
            sum += nums[end];
            
            while ((sum * (end - start + 1)) >= k) {
                sum -= nums[start];
                start++;
            }
            
            result += end - start + 1;
        }
        
        return result;
    }
};

// TC: O(n^2)
// SC: O(1)