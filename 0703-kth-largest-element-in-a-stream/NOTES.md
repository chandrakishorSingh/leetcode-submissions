Solution 1:
​
- Straightforward min-heap based solution.
​
```
class KthLargest {
public:
int k;
priority_queue<int, vector<int>, greater<int>> pq;
KthLargest(int k, vector<int>& nums) {
this->k = k;
for (int i = 0; i < nums.size(); i++) {
if (i < k) {
pq.push(nums[i]);
continue;
}
​
if (nums[i] > pq.top()) {
pq.pop();
pq.push(nums[i]);
}
}
}
int add(int val) {
if (pq.size() < k) {
pq.push(val);
} else if (val > pq.top()) {
pq.pop();
pq.push(val);
}
return pq.top();
}
};
​
/**
* Your KthLargest object will be instantiated and called as such:
* KthLargest* obj = new KthLargest(k, nums);
* int param_1 = obj->add(val);
*/
​
// KthLargest(int k, vector<int>& nums)
// TC: O(len(nums) * log(k))
// SC: O(k)
​
// int add(int val)
// TC: (log(k))
// SC: O(1)
```