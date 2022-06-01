class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result(nums.size());
        
        partial_sum(nums.begin(), nums.end(), result.begin());
        
        return result;
    }
};