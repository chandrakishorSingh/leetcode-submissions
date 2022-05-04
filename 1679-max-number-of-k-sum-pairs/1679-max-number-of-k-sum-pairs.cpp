class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        
        unordered_map<int, int> freq;
        for (auto num: nums) {
            if (freq.count(k - num) && freq[k - num] > 0) {
                count++;
                freq[k - num]--;
            } else {
                freq[num]++;
            }
        }
        
        return count;
    }
};

// TC: O(n^2)
// SC: O(1)