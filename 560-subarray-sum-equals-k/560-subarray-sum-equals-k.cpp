class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> cumulativeSumFreq;
        cumulativeSumFreq[0] = 1;
        
        int cumulativeSum = 0;
        int result = 0;
        for (auto num: nums) {
            cumulativeSum += num;
            
            if (cumulativeSumFreq.count(cumulativeSum - k))
                result += cumulativeSumFreq[cumulativeSum - k];
            
            cumulativeSumFreq[cumulativeSum]++;
        }
        
        return result;
    }
};