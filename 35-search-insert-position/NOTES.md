Solution 1:
​
- Simple iterative binary search
- I observed that whenever the target is not found, the value of `low` always denotes the correct index and hence I use it.
- It is important to note that this implementation works because of array values being distinct
​
```
class Solution {
public:
int searchInsert(vector<int>& nums, int target) {
int low = 0;
int high = nums.size() - 1;
while (low <= high) {
int mid = low + (high - low) / 2;
if (nums[mid] == target)
return mid;
else if (nums[mid] > target) {
high = mid - 1;
} else {
low = mid + 1;
}
}
return low;
}
};
​
// TC: O(log(n))
// SC: O(1)
```
​
Solution 2:
​
- Same as 1st one just recursive binary search
​