int _minMaxGame(vector<int>& nums, int size) {
if (size == 1)
return nums[0];
int pairty = 0;
for (int i = 0; i < size / 2; i++) {
if (!pairty)
nums[i] = min(nums[2 * i], nums[2 * i + 1]);
else
nums[i] = max(nums[2 * i], nums[2 * i + 1]);
pairty = 1 - pairty;
}
return _minMaxGame(nums, size / 2);
}
};
​
// TC: O(n)
// SC: O(log(n))
```
​
Solution 2:
​
- Iterative version of above same approach
​
```
class Solution {
public:
int minMaxGame(vector<int>& nums) {
int n = nums.size();
while (n != 1) {
int pairty = 0;
for (int i = 0; i < n / 2; i++) {
if (!pairty)
nums[i] = min(nums[2 * i], nums[2 * i + 1]);
else
nums[i] = max(nums[2 * i], nums[2 * i + 1]);
​
pairty = 1 - pairty;
}
n /= 2;
}
return nums[0];
}
};
​
// TC: O(n)
// SC: O(1)
```