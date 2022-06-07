class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (auto num: nums)
            result ^= num;
        
        return result;
    }
};

// TC: O(n)
// SC: O(1)