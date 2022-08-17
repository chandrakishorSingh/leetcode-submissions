class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int first = nums[0] - 1;
        int second = first;
        set<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (first == nums[i] && second == nums[j])
                    continue;
                
                first = nums[i];
                second = nums[j];
                
                int target = -(nums[i] + nums[j]);
                auto it = lower_bound(nums.begin() + j + 1, nums.end(), target);
                
                if (it != nums.end() && *it == target)
                    result.insert({ nums[i], nums[j], target });
            }
        }
        
        return vector<vector<int>>(result.begin(), result.end());
    }
};

// TC: O(n^3 * log(n))
// SC: O(1), except the output