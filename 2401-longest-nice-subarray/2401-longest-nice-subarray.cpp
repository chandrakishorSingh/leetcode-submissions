class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int result = 0;
        
        int start = 0;
        int cumulativeOR = 0;
        for (int end = 0; end < nums.size(); end++) {
            while ( isSetBitIntersects(cumulativeOR, nums[end]) ) {
                cumulativeOR ^= nums[start++];
            }
            
            cumulativeOR |= nums[end];
            
            result = max(result, end - start + 1);
        }
        
        return result;
    }
    
    bool isSetBitIntersects(int num1, int num2) {
        for (int i = 31; i >= 0; i--) {
            auto bit1 = (num1 & (1 << i)) > 0 ? 1 : 0;
            auto bit2 = (num2 & (1 << i)) > 0 ? 1 : 0;
            
            if (bit1 == 1 && bit2 == 1)
                return true;
        }
        
        return false;
    }
};