Solution 1:
​
- Since, the length of array is very small(<= 100), we can use bucket sort to find pairs.
​
```
class Solution {
public:
vector<int> numberOfPairs(vector<int>& nums) {
vector<int> buckets(101);
for (auto num: nums) {
buckets[num]++;
if (buckets[num] == 2)
buckets[num] = 0;
}
vector<int> result(2);
for (int i = 0; i <= 100; i++) {
if (buckets[i] == 1)
result[1]++;
}
result[0] = (nums.size() - result[1]) / 2;
return result;
}
};
​
// TC: O(max(100, n))
// SC: O(max(nums) - min(nums))
```