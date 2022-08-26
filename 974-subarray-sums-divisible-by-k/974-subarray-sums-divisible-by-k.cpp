class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumRemainderFreq;
        prefixSumRemainderFreq[0] = 1;
        
        int result = 0;
        int sum = 0;
        for (auto num: nums) {
            sum += num;
            
            int key = mod(sum, k);
            if (prefixSumRemainderFreq.count(key))
                result += prefixSumRemainderFreq[key];
            
            prefixSumRemainderFreq[key]++;
        }
        
        return result;
    }
    
    int mod(int num, int m) {
        int result = num % m;
        return result < 0 ? result + m : result;
    }
};