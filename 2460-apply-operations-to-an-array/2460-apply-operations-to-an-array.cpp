class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        vector<int> result;
        int current = nums[0];
        int next;
        for (int i = 1; i < n; i++) {
            next = nums[i];
            if (current == next) {
                current *= 2;
                next = 0;
            }
            
            if (current != 0)
                result.push_back(current);
            
            current = next;
        }
        
        result.push_back(next);
        result.resize(n, 0);

        return result;
    }
};

// TC: O(n)
// SC: O(n)