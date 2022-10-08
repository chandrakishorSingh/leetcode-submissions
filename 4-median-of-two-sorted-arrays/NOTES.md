Solution 1(TLE):
​
- Traverse the two arrays using two pointers and increment them appropriately so that you can find the middle element(s).
​
```
class Solution {
public:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
int n1 = nums1.size();
int n2 = nums2.size();
int middleIndex = (n1 + n2) / 2 + 1;
int i = 0;
int j = 0;
int previousElement = 0;
int middleElement = 0;
while (middleIndex--) {
previousElement = middleElement;
if (i == n1) {
middleElement = nums2[j++];
} else if (j == n2) {
middleElement = nums1[i++];
} else if (nums1[i] <= nums2[j]) {
middleElement = nums1[i++];
} else {
middleElement = nums2[j++];
}
}
​
return (n1 + n2) % 2 == 0 ? ((middleElement + previousElement) / 2.0): middleElement;
}
};
// TC: O(m + n)
// SC: O(1)
```
​
Solution 2:
​
- If we just remove all the elements of the first half of the array obtained after sorting the combined elements of given two arrays then the required median can be found out easily. It will either be the first element or the average of the first two elements of the remaining array depending upon whether the size of the array was odd or even.
- This can easily be achieved using a min heap.
​
```
class Solution {