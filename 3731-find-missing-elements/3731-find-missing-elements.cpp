class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int largest = *max_element(nums.begin(), nums.end());
        int smallest = *min_element(nums.begin(), nums.end());
        
        int n = largest - smallest + 1;
        vector<int> visited(n);
        for (auto num: nums) {
            visited[num - smallest] = 1;
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                result.push_back(smallest + i);
            }
        }
        
        return result;
    }
};

// TC: O(max(nums) - min(nums))
// SC: O(max(nums) - min(nums))