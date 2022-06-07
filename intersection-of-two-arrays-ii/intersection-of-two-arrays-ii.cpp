class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        
        unordered_map<int, int> freq;
        for (auto num: nums1)
            freq[num]++;
        
        for (auto num: nums2) {
            auto it = freq.find(num);
            
            if (it == freq.end() || it->second == 0)
                continue;
            
            it->second--;
            result.push_back(num);
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(max(n, m)) 
// n, m are size of arrays