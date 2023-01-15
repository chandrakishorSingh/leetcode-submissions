class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> matches(n);
        map<int, int> freq;
        
        long long result = 0;
        int start = 0;
        int matchCount = 0;
        for (int end = 0; end < n; end++) {
            freq[nums[end]]++;
            
            if (freq[nums[end]] > 1) {
                matchCount += freq[nums[end]] - 1;
            }
            
            while (matchCount >= k) {
                result += n - end;

                matchCount -= freq[nums[start]] - 1;
                freq[nums[start]]--;
                start++;
            }
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(n)