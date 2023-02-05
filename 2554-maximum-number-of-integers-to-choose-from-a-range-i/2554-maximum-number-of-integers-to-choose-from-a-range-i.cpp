class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> nums(n + 1);
        for (auto num: banned) {
            if (num <= n) {
                nums[num] = 1;
            }
        }
        
        int result = 0;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (nums[i]) {
                continue;
            }
            
            if (sum + i > maxSum) {
                break;
            }
            
            sum += i;
            result++;
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(n)