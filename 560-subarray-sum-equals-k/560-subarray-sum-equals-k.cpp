class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cumulativeSumFreq;
        cumulativeSumFreq[0] = 1;
        
        int cumulativeSum = 0;
        int result = 0;
        for (auto num: nums) {
            cumulativeSum += num;
            
            auto it = cumulativeSumFreq.find(cumulativeSum - k);
            if (it != cumulativeSumFreq.end())
                result += it->second;
            
            cumulativeSumFreq[cumulativeSum]++;
        }
        
        return result;
    }
};