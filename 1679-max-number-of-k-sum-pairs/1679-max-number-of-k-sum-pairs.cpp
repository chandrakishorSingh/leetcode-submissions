class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int count = 0;
        int start = 0;
        int end = nums.size() - 1;
        while (start < end) {
            int sum = nums[start] + nums[end];
            
            if (sum > k)
                end--;
            else if (sum < k)
                start++;
            else {
                count++;
                start++;
                end--;
            }
        }
        
        return count;
    }
};

// TC: O(n*log(n))
// SC: O(1)