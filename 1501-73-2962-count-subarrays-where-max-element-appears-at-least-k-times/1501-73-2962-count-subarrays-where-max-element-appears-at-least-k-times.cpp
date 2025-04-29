class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long result = 0;
        
        int maxElement = *max_element(nums.begin(), nums.end());
        int start = 0;
        int count = 0;
        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] == maxElement) {
                count++;
            }
            
            while (count == k) {
                result += nums.size() - end;
                
                if (nums[start] == maxElement) {
                    count--;
                }
                start++;
            }
        }
        
        return result;
    }
};