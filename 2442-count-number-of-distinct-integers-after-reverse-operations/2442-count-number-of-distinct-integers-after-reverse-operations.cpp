class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        
        for (auto num: nums) {
            auto numString = to_string(num);
            reverse(numString.begin(), numString.end());
            
            st.insert(stoi(numString));
        }
        
        return st.size();
    }
};

// TC: O(n * log(n))
// SC: O(n)