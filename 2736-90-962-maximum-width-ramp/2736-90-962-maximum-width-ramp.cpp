class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> maximumFromRight(n);
        maximumFromRight[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maximumFromRight[i] = max(maximumFromRight[i + 1], nums[i]);
        }
        
        int i = 0;
        int j = 0;
        int result = 0;
        while (i < n && j < n) {
            if (nums[i] <= maximumFromRight[j]) {
                result = max(result, j - i);
                j++;
            } else {
                i++;
            }
        }
        
        return result;
    }
};