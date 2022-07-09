class Solution {
public:
    int jump(vector<int>& nums) {
        int currentJumpReach = 0;
        int nextJumpReach = nums[0];
        int result = 0;

        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nextJumpReach >= n - 1)
                return result + 1;
            
            if (i > currentJumpReach) {
                currentJumpReach = nextJumpReach;
                result++;
            }
            
            nextJumpReach = max(nextJumpReach, i + nums[i]);
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(1)