class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        for (int i = 0; i < 32; i++)
            result += ((1 << i) & n) ? 1: 0;
        
        return result;
    }
};
// TC: O(1)
// SC: O(1)