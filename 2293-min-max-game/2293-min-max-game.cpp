class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        
        while (n != 1) {
            int pairty = 0;
            for (int i = 0; i < n / 2; i++) {
                if (!pairty)
                    nums[i] = min(nums[2 * i], nums[2 * i + 1]);
                else
                    nums[i] = max(nums[2 * i], nums[2 * i + 1]);

                pairty = 1 - pairty;
            }
            
            n /= 2;
        }
        
        return nums[0];
    }
};

// TC: O(n)
// SC: O(log(n))