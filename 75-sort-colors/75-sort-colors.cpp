class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                zeroCount++;
            else if (nums[i] == 1)
                oneCount++;
            else {
                twoCount++;
            }
        }
        
        int index = 0;
        for (; zeroCount; index++, zeroCount--)
            nums[index] = 0;
        
        for (; oneCount; index++, oneCount--)
            nums[index] = 1;
        
        for (; twoCount; index++, twoCount--)
            nums[index] = 2;
    }
};

// TC: O(n)
// SC: O(1)