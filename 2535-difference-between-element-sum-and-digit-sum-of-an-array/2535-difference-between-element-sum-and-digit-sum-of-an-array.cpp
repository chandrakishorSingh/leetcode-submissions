class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = accumulate(nums.begin(), nums.end(), 0);
        int digitSum = getDigitSum(nums);
        
        return abs(elementSum - digitSum);
    }
    
    int getDigitSum(vector<int>& nums) {
        int result = 0;
        for (auto num: nums) {
            while (num != 0) {
                result += num % 10;
                num /= 10;
            }
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(1)