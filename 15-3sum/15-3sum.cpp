class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            if (nums[i] > 0)
                break;
            
            twoSum(-nums[i], i + 1, nums, result);
        }
        
        return result;
    }
    
    void twoSum(int target, int startIndex, vector<int>& nums, vector<vector<int>>& result) {
        int left = startIndex;
        int right = nums.size() - 1;
        int num1 = nums[left] - 1;
        int num2 = nums[right] + 1;
        
        while (left < right) {
            if (nums[left] == num1) {
                left++;
                continue;
            }
            
            if (nums[right] == num2) {
                right--;
                continue;
            }
            
            int sum = nums[left] + nums[right];
            if (sum == target) {
                num1 = nums[left];
                num2 = nums[right];
                
                result.push_back({ -target, nums[left], nums[right] });
                
                left++;
                right--;
            } else if (sum > target) {
                right--;
            } else {
                left++;
            }
        }
    }
};

// TC: O(n^2)
// SC: O(1), except the output