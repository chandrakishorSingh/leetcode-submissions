class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        int result = -1;
        for (int i = 0; i < min(k + 1, n); i++) {
            if ((k - i) % 2 == 0)
                result = max(result, nums[i]);
            else if (k - i == 1)
                continue;
            else if (i > 0 || i != n - 1)
                result = max(result, nums[i]);
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(1)