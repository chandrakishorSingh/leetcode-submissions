class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key) {
                int start = max(result.size() ? result.back() + 1: 0, i - k);
                
                for (int j = start; j <= min(i + k, (int)nums.size() - 1); j++)
                    result.push_back(j);
            }
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(n)