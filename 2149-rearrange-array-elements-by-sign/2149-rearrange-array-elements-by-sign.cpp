class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int evenIndex = 0;
        int oddIndex = 1;
        
        vector<int> result(nums.size());
        for (auto num: nums) {
            if (num > 0) {
                result[evenIndex] = num;
                evenIndex += 2;
            } else {
                result[oddIndex] = num;
                oddIndex += 2;
            }
        }
        
        return result;
    }
};