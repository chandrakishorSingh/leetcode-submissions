store[i][0] = 1;
for (int i = 0; i < targetSum + 1; i++)
store[0][i] = 0;
​
for (int i = 1; i < n + 1; i++) {
for (int j = 1; j < targetSum + 1; j++) {
if (nums[i - 1] > j)
store[i][j] = store[i - 1][j];
else
store[i][j] = store[i - 1][j] || store[i - 1][j - nums[i - 1]];
}
}
return store[n][targetSum] == 1;
}
};
​
// TC: O(n * sum(arr))
// SC: O(n * sum(arr))
```
​
Solution 4:
​
- Same Bottom-Up approach but better space complexity thanks to the observations.
​
```
class Solution {
public:
bool canPartition(vector<int>& nums) {
int n = nums.size();
int totalSum = accumulate(nums.begin(), nums.end(), 0);
​
if (totalSum & 1)
return false;
​
int targetSum = totalSum / 2;
vector<int> store(targetSum + 1, -1);
for (int i = 0; i < targetSum + 1; i++)
store[i] = 0;
store[0] = 1;
​
for (int j = 0; j < n; j++)
for (int i = targetSum; i > 0; i--)
if (nums[j] <= i)
store[i] = store[i] || store[i - nums[j]];
return store[targetSum] == 1;
}
};
​
// TC: O(n * sum(arr))
// SC: O(sum(arr))
```