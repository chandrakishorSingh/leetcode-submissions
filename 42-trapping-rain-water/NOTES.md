};
​
// TC: O(n * max. height of bars)
// SC: O(1)
```
​
Solution 2:
​
- Observations
- For each of the height, we just need to know how many "blocks" of water can be placed over this bar without spilling the water.
- we can place `k` blocks of water over a bar of height `h` if there are walls of at least `k + h` height in the left and right side of this bar.
- Since, we can't spill the water, we can place maximum of `k` blocks of water above a bar of height `h` such that `k = min(max height in right of ith block, max height in left of ith block)`
​
```
class Solution {
public:
int trap(vector<int>& height) {
int n = height.size();
vector<int> maxFromLeft(n);
vector<int> maxFromRight(n);
for (int i = 1; i < n; i++)
maxFromLeft[i] = max(maxFromLeft[i - 1], height[i - 1]);
for (int i = n - 2; i >= 0; i--)
maxFromRight[i] = max(maxFromRight[i + 1], height[i + 1]);
int result = 0;
for (int i = 1; i < n - 1; i++)
if (min(maxFromLeft[i], maxFromRight[i]) > height[i])
result += min(maxFromLeft[i], maxFromRight[i]) - height[i];
return result;
}
};
​
// TC: O(n)
// SC:: O(n)
```