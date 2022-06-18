class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st(nums1.begin(), nums1.end());
        
        vector<int> result;
        for (auto num: nums2) {
            if (st.count(num)) {
                result.push_back(num);
                st.erase(num);
            }
        }
        
        return result;
    }
};