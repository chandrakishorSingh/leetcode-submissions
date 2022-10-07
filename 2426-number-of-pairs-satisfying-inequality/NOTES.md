Solution 1(Brute-Force, TLE):
​
- Check for every possible pair.
​
```
class Solution {
public:
long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
int n = nums1.size();
long long result = 0;
for (int i = 0; i < n; i++)
for (int j = i + 1; j < n; j++)
if (nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff)
result++;
return result;
}
};
​
// TC: O(n^2)
// SC: O(1)
```
​
Solution 2:
​
- The equation can be written as `nums1[i] - nums2[i] - d <= nums1[j] - nums2[j]` or `differences[i] - d <= differences[j]` where `differences[i]` stores `nums1[i] - nums2[i]`.
- So basically this problem reduces to finding a pair of index where this condition holds true.
- If `d = 0`, then this problem is essentially finding non-inversion pairs which can easily be solved using merge sort. Even for other values of d, we can use the same technique as the problem itself is divide and conquer kind. That means, the count of such pairs is equal to the count of such pair in first half + count of such pair in second half + count of such pair across the halves.
​
```
class Solution {
public:
long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
int n = nums1.size();
vector<int> differences(n), aux(n);
for (int i = 0; i < n; i++) {
differences[i] = nums1[i] - nums2[i];
}
long long result = 0;
mergeSort(differences, aux, 0, n - 1, diff, result);