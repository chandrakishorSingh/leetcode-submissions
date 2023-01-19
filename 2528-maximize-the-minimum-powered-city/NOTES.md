Solution 1:
​
- It's easy to realize that coming up with a closed form equation for finding the answer to this problem is not easy.
- The right question to ask in this situation is "Can we raise the minimum power of every city to x ?"
- It is easy to answer this question by doing little simulation. We can use the given stations to see whether it's possible to do it or not.
- This placement of stations in this task should be done in a greedy manner. This is because if there is a requirement of y units of power at position i then placing the stations at position i + r would be optimal. This is because cities at position < i didn't needed additional power. Also, this task would take linear time.
- Also, we're sure that the answer would lie somewhere between `min(stations)` and `sum(stations)`. So, we can use binary search here.
​
```
class Solution {
public:
long long maxPower(vector<int>& stations, int r, int k) {
int n = stations.size();
vector<long long> power(n);
long long sum = 0;
for (int i = 0; i < n; i++) {
sum += stations[i];
if (i >= r) {
sum -= (i >= (2 * r + 1)) ? stations[i - (2 * r + 1)] : 0;
power[i - r] = sum;
}
}