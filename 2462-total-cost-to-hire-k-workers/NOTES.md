NOTE:
​
- Make the code more concise(Can take count of workers from both direction instead of indices)
​
Solution 1:
​
- Straightforward priority queue problem.
​
```
class Solution {
public:
long long totalCost(vector<int>& costs, int k, int candidates) {
long long result = 0;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int left = -1;
int right = costs.size();
int count = 0;
for (; (left + 1 < right) and (count < candidates); left++, count++) {
pq.push({ costs[left + 1], left + 1 });
}
count = 0;
for (; (right - 1 > left) and (count < candidates); right--, count++) {
pq.push({ costs[right - 1], right - 1 });
}
while (k--) {
auto top = pq.top();