class Solution {
public:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
priority_queue<int> pq;
for (auto num: nums1)
pq.push(num);
for (auto num: nums2)
pq.push(num);
int totalSize = nums1.size() + nums2.size();
int expectedSize = totalSize / 2 + 1;
while (pq.size() != expectedSize)
pq.pop();
double result = pq.top();
if (totalSize % 2 == 0) {
pq.pop();
result += pq.top();
result /= 2.0;
}
return result;
}
};
// TC: O((m + n) * log(m + n))
// SC: O(m + n)
```