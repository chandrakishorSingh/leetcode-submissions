class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int result = 0;
        for (int i = 1; i < nums.size(); i++)
            result += nums[i] - nums[0];
        
        return result;
    }
};