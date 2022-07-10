class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int start = -1;
        int end = n;
        
        while (end - start > 1) {
            if (nums[start + 1] <= 0) {
                start++;
                continue;
            }
            
            swap(nums[start + 1], nums[end - 1]);
            end--;
        }
        
        int offset = start + 1;
        int length = n - end;
        for (int i = 0; i < length; i++) {
            if (abs(nums[i + offset]) <= length)
                nums[offset + abs(nums[i + offset]) - 1] = -abs(nums[offset + abs(nums[i + offset]) - 1]);
        }
        
        int result = length + 1;
        for (int i = 0; i < length; i++) {
            if (nums[i + offset] > 0) {
                result = i + 1;
                break;
            }
        }
        
        return result;
    }
};