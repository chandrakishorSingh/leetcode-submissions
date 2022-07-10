Solution 1:
​
Place all the positive numbers at the beginning(end would be fine as well, though no need to make it complex) of the array. Then, mark the position `i - 1` if there is a positive number `i`. Note that the index `i - 1` may not exist if `i` > `n`. This marking is done by making the element at `i - 1` negative(if it is not already by previous such marking).
​
```
class Solution {
public:
int firstMissingPositive(vector<int>& nums) {
int positiveCount = 0;
for (int i = 0; i < nums.size(); i++)
if (nums[i] > 0)
swap(nums[positiveCount++], nums[i]);
for (int i = 0; i < positiveCount; i++) {
if (abs(nums[i]) > positiveCount || nums[abs(nums[i]) - 1] < 0)
continue;
else
nums[abs(nums[i]) - 1] *= -1;
}
for (int i = 0; i < positiveCount; i++)
if (nums[i] > 0)
return i + 1;
return positiveCount + 1;
}
};
​
// TC: O(n)
// SC: O(1)
```
​
Solution 2:
​
Another(and probably simpler) approach would be to place positive numbers `i` to index `i - 1`. Then the first position where index is not equal to the corresponding element - 1 would be the answer
​
Try to implement