class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st;
        
        int result = -1;
        for (auto num: nums) {
            st.insert(num);
            
            if (st.count(num) && st.count(-num))
                result = max(result, abs(num));
        }
        
        return result;
    }
};

// TC: O()