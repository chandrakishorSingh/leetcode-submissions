Solution 1:
​
- The variable `status` is used keep track of what kind of object(hill or valley) is expected to be seen in future.
- If `status` is 0 then it means increasing part of hill is seen and if a decreasing part will be seen in the future then count will be incremented.
- If `status` is 1 then it means decreasing part of valley is seen and if a increasing part will be seen in the future then count will be incremented.
- When `status` is -1 then it means neither increasing part of decreasing part is seen.
​
```
class Solution {
public:
int countHillValley(vector<int>& nums) {
int count = 0;
// -1: null, 0: hill, 1: valley
int status = -1;
for (int i = 0; i < nums.size() - 1; i++) {
if (nums[i] < nums[i + 1]) {
if (status == -1) {
status = 0;
} else if (status == 1) {
status = 0;
count++;
}
} else if (nums[i] > nums[i + 1]) {
if (status == -1) {
status = 1;
} else if (status == 0) {
status = 1;
count++;
}
}
}
return count;
}
};
​
// TC: O(n)
// SC: O(1)
```
​
​