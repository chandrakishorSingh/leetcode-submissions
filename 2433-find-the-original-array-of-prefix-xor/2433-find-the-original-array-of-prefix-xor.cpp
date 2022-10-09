class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> result(n, pref[0]);
        
        for (int i = 1; i < n; i++)
            result[i] = pref[i] ^ pref[i - 1];
        
        return result;
    }
};

// TC: O(n)
// SC: O(1), except the output