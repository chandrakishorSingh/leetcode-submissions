int missingNumber(vector<int>& nums) {
int result = 0;
for (int i = 1; i <= nums.size(); i++) {
result ^= i;
result ^= nums[i - 1];
}
return result;
}
};
​
// TC: O(n)
// SC: O(1)
```
​
Solution 3:
​
- Using BS.
- The desired space is when nums[i] != i(basically nums[i] = i + 1).
- The way I write BS, left will always store the right result.
​
```
class Solution {
public:
int missingNumber(vector<int>& nums) {
sort(nums.begin(), nums.end());
int low = 0;
int high = nums.size() - 1;
while (low <= high) {
int mid = low + (high - low) / 2;
if (nums[mid] == mid)
low = mid + 1;
else
high = mid - 1;
}
return low;
}
};
​
// TC: O(n * log(n))
// SC: O(1)
```