class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        bool result = false;
        unordered_set<int> st;
        
        for (int i = 1; i < nums.size(); i++) {
            int sum = nums[i] + nums[i - 1];
            
            if (st.count(sum)) {
                result = true;
                break;
            }
            
            st.insert(sum);
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(1)