class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;

        unordered_map<int, int> cumulativeSumFreq({{0, 1}});
        int cumulativeSum = 0;
        for (int i = 0; i < n; i++) {
            cumulativeSum += nums[i];
            
            if (cumulativeSumFreq.count(cumulativeSum - k)) {
                result += cumulativeSumFreq[cumulativeSum - k];
            }
            
            cumulativeSumFreq[cumulativeSum]++;
        }
        
        return result;
    }
};

// TC: O(n^2)
// SC: O(1)