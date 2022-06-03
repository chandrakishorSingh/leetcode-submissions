TODO:
​
- Solve using stack and two-pointers approach.
​
Solution 1(Brute-Force)
​
- Slice down the bottom row at a time. While doing so, count the number of empty blocks.
- Make sure that all empty block are inside the pillers
​
```
class Solution {
public:
int trap(vector<int>& height) {
int maxHeight = *max_element(height.begin(), height.end());
int result = 0;
for (int i = 0; i < maxHeight; i++) {
int waterBlockCount = 0;
bool isFirstBarSeen = false;
for (int j = 0; j < height.size(); j++) {
if (isFirstBarSeen && height[j] == 0) {
waterBlockCount++;
continue;
}
if (height[j] != 0 && isFirstBarSeen) {
result += waterBlockCount;
waterBlockCount = 0;
height[j]--;