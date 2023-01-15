Solution 1(Sliding window):
​
- It's easy to figure out that this is a sliding window problem. If you have got k matches in the subarray a[i:j] then we obviously got at least k matches in a[i:j + 1], a[i:j + 2], ..., a[i:n - 1].
- To count the matches in the current window, we need an efficient way of finding how many times the current element has repeated. This can be done using a dictionary.
​
```
class Solution {
public:
long long countGood(vector<int>& nums, int k) {
int n = nums.size();
vector<int> matches(n);
unordered_map<int, int> freq;
long long result = 0;
int start = 0;
int matchCount = 0;
for (int end = 0; end < n; end++) {
freq[nums[end]]++;
if (freq[nums[end]] > 1) {
matchCount += freq[nums[end]] - 1;
}
while (matchCount >= k) {
result += n - end;
​
matchCount -= freq[nums[start]] - 1;
freq[nums[start]]--;
start++;
}
}
return result;
}
};
​
// TC: Θ(n)
// SC: O(n)
```