class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int result = 0;
        int sum = 0;
        int start = 0;
        unordered_map<int, int> lastIndex;
        for (int end = 0; end < n; end++) {
            if (lastIndex.count(nums[end])) {
                int newStart = lastIndex[nums[end]] + 1;
                
                while (start != newStart) {
                    sum -= nums[start];
                    lastIndex.erase(nums[start]);
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