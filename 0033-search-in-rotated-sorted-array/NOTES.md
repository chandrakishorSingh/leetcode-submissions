NOTE:
​
- BS doesn't need to have only 2 conditions(either go to left or right) to work.
- It can be generalized where we could have n number of choices. In such cases as well we can reduce the search space. The core idea is that the search space should be continuous on these conditions i.e., all values that form one "bucket" should be next to each other(in some sense of distance) and then all other values that form some other "bucket" should be next to each other and so on.
​
Solution 1:
​
- Find the pivot position where the array is rotated from and apply binary search on both the partitions.
​
```
class Solution {
public:
int search(vector<int>& vec, int k) {
int n = vec.size();
int left1 = 0;
int right1 = n - 1;
int left2 = -1;
int right2 = -1;
​
for (int i = 1; i < n; i++) {
if (vec[i] < vec[i - 1]) {