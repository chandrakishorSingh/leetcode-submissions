class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> numExists;
        for (auto num: nums1)
            numExists[num] = 1;
        
        vector<int> result;
        for (auto num: nums2) {
            if (numExists[num] == 1) {
                result.push_back(num);
                numExists[num] = 0;
            }
        }
        
        return result;
    }
};

// TC: O(n*log(n) + m * log(n))
// SC: O(n)
// n, m are size of two arrays