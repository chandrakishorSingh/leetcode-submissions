};
​
// TC: O(n^2)
// SC: O(1)
```
​
Solution 3:
​
- It's the same question that I saw Sandeep(GFG) was solving in a video.
- The idea is to find the subarray as we are traversing it.
- If there is a subarray that sum to k and ends at the current position then there should be some subarray(s) that sum to `cs - k` where `cs` is the cumulative sum till the current position.
- To handle the edge case when the subarray starts at the first index, we should add a cumulative sum of 0 when no array elements are seen yet.
​
```
class Solution {
public:
int subarraySum(vector<int>& nums, int k) {
unordered_map<int, int> cumulativeSumFreq;
cumulativeSumFreq[0] = 1;
int cumulativeSum = 0;
int result = 0;
for (auto num: nums) {
cumulativeSum += num;
auto it = cumulativeSumFreq.find(cumulativeSum - k);
if (it != cumulativeSumFreq.end())
result += it->second;
cumulativeSumFreq[cumulativeSum]++;
}
return result;
}
};
​
// TC: Θ(n)
// SC: O(n)
```