class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; k = k % n; i += k, n -= k) {
            for (int j = 0; j < k; j++)
                swap(nums[i + j], nums[nums.size() - k + j]);
        }
    }
};

// TC: O(n)
// SC: O(1)