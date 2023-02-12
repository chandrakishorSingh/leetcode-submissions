class Solution {
public:
    typedef long long ll;
    
    long long findTheArrayConcVal(vector<int>& nums) {
        ll result = 0;
        
        int left = 0;
        int right = nums.size() - 1;
        for (; left <= right; left++, right--) {
            if (left < right) {
                result += stoi(to_string(nums[left]) + to_string(nums[right]));
            } else {
                result += nums[left];
            }
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(1)