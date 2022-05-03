Solution 1:
​
- Create a copy of array and sort it.
- If at the same position, the elements are different then it means the original element has been replaced to some other position. Hence it was part of that subarray.
- The subarray will start from the position where first such element is found from left and will end at position where first such element is found from the right.
​
```
class Solution {
public:
int findUnsortedSubarray(vector<int>& nums) {
vector<int> copy(nums.begin(), nums.end());
sort(copy.begin(), copy.end());
int start = -1;
int end = -1;
for (int i = 0; i < nums.size(); i++) {
if (copy[i] != nums[i]) {
start = i;
break;
}
}
for (int i = nums.size() - 1; i >= 0; i--) {
if (nums[i] != copy[i]) {
end = i;
break;
}
}
if (start == -1)
return 0;
return end - start + 1;
}
};
​
// TC: O(n*log(n))
// SC: O(n)
```