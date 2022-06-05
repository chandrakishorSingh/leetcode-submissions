int newElement = operation[1];
int index = numToIndex[prevElement];
nums[index] = newElement;
numToIndex[newElement] = index;
}
return nums;
}
};
​
// TC: O(n)
// SC: O(n + len(operations))
```
​
Solution 2:
​
- Same as 1st one but here the entry w.r.t. previous element(which is being replaced) is deleted as it's no longer needed.
​
```
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
numToIndex.erase(prevElement);
}
return nums;
}
};
​
// TC: O(n)
// SC: O(n)
```
​