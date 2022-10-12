Solution 1:
​
​
```
class Solution {
public:
int triangleNumber(vector<int>& nums) {
int result = 0;
for (int i = 0; i < nums.size(); i++)
for (int j = i + 1; j < nums.size(); j++)
for (int k = j + 1; k < nums.size(); k++)
if (isValidTriangleSides(nums[i], nums[j], nums[k]))
result++;
return result;
}
bool isValidTriangleSides(int a, int b, int c) {
if (a == 0 || b == 0 || c == 0)
return false;
if (a + b <= c || b + c <= a || c + a <= b)
return false;
if (abs(a - b) >= c || abs(b - c) >= a || abs(c - a) >= b)
return false;
return true;
}
};
​
// TC: O(n^3)
// SC: O(1)
```
​
Solution 2:
​
```
class Solution {
public:
int triangleNumber(vector<int>& nums) {
sort(nums.begin(), nums.end());
int result = 0;