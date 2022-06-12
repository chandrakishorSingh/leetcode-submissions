class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int result = 0;
        int sum = 0;
        int start = 0;
        unordered_map<int, int> lastIndex;
        for (int end = 0; end < n; end++) {
            if (lastIndex.find(nums[end]) != lastIndex.end() && start <= lastIndex[nums[end]]) {
                int newStart = lastIndex[nums[end]] + 1;
                
                while (start != newStart) {
                    sum -= nums[start];
                    start++;
                }
            }

            lastIndex[nums[end]] = end;
     
            sum += nums[end];
            result = max(result, sum);
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(n)