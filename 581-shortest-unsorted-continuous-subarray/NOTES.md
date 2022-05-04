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
​
Solution 2:
​
- Find wheather every element is at its final position or not. An element will be at its final position if all element to its right are not smaller than it and all element to its left are not larger than it.
- This can be achieved using prefix and suffix arrays.
- The required subarray will begin at left most element which is not at its final position and will end at right most element which is not at its final position.
​
```
class Solution {
public:
int findUnsortedSubarray(vector<int>& nums) {
int n = nums.size();
vector<int> smallestFromRight(n, nums[n - 1]);
vector<int> largestFromLeft(n, nums[0]);
for (int i = n - 2; i >= 0; i--)
smallestFromRight[i] = min(nums[i], smallestFromRight[i + 1]);
for (int i = 1; i < n; i++)
largestFromLeft[i] = max(nums[i], largestFromLeft[i - 1]);
int start = -1;