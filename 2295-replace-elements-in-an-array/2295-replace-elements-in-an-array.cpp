class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> numToIndex;
        for (int i = 0; i < nums.size(); i++)
            numToIndex[nums[i]] = i;
        
        for (auto& operation: operations) {
            int prevElement = operation[0];
            int newElement = operation[1];
            int index = numToIndex[prevElement];
            
            nums[index] = newElement;
            numToIndex[newElement] = index;
        }
        
        return nums;
    }
};