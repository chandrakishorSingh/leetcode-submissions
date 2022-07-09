class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, INT_MAX);
        result[0] = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= nums[i] && result[i] != INT_MAX; j++) {
                if (i + j < n)
                    result[i + j] = min(result[i + j], result[i] + 1);
            }
        }
        
        return result[n - 1];
    }
};