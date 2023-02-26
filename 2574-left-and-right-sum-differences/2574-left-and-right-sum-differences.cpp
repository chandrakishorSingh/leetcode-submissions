class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        int leftSum = 0;
        int rightSum = accumulate(nums.begin() + 1, nums.end(), 0);
        
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = abs(leftSum - rightSum);
            
            leftSum += nums[i];
            rightSum -= i == n - 1 ? 0 : nums[i + 1];
        }
        
        return result;
    }
};