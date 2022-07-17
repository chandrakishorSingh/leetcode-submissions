class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> buckets(101);
        
        for (auto num: nums) {
            buckets[num]++;
        }
        
        vector<int> result(2);
        for (int i = 0; i <= 100; i++) {
            result[0] += buckets[i] / 2;
            result[1] += buckets[i] % 2;
        }
        
        return result;
    }
};

// TC: O(max(100, n))
// SC: O(max(nums) - min(nums))