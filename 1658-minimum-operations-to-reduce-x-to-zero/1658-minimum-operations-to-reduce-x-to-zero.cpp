class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        int sum = 0;
        for (auto num: nums)
            sum += num;
        
        if (sum < x)
            return -1;
        
        int i = n - 1;
        int j = n;
        int result = INT_MAX;
        while (i >= 0 || j >= 0) {
            if (sum == x) {
                result = min(result, i + 1 + n - j);

                if (i == -1)
                    break;
                
                sum -= nums[i--];
            } else if (sum > x) {
                if (i == -1)
                    break; 
                
                sum -= nums[i--];
            } else {
                if (j == 0)
                    break;
                
                sum += nums[--j];
            }
        }
        
        return result == INT_MAX ? -1 : result;
    }
};

// TC: O(n * log(n))
// SC: O(n)