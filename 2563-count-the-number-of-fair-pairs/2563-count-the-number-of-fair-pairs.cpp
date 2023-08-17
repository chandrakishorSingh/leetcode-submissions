class Solution {
public:
    typedef long long ll;
    
    ll countLess(vector<int>& nums, int val) {
        ll result = 0;
        
        int left = 0;
        int right = nums.size() - 1;
        for (; left < right; left++) {
            while (left < right && nums[left] + nums[right] > val) {
                right--;
            }
            
            result += right - left;
        }
        
        return result;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        
        return countLess(nums, upper) - countLess(nums, lower - 1);
    }
};

// TC: O(n * log(n))
// SC: O(sort())