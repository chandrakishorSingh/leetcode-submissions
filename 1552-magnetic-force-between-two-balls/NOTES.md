TODO
​
- see other approaches
​
Solution 1:
​
- The problem was solved the moment I've answered the question "Given a gap, can you efficiently find out whether we can place balls with this gap ?"
- Yes. It just takes O(n) time to do it. We will start placing the balls in the increasing order of their position starting with `position[0]`. As soon as we get a position `position[i]` such that `position[i] - position[position of last placed ball] > given gap` then we will place a ball at this position `position[i]`. It's not hard to see that if there is some other configuration of placements of balls then this approach will also give a valid placement.
​
```
class Solution {
public:
int maxDistance(vector<int>& position, int m) {
sort(position.begin(), position.end());
int n = position.size();
int minGap = INT_MAX;
for (int i = 1; i < n; i++)
minGap = min(minGap, position[i] - position[i - 1]);
int low = minGap;
int high = position.back() - position.front();
int result = minGap;
while (low <= high) {
int mid = low + (high - low) / 2;
if (canPlace(mid, position, m)) {
result = mid;
low = mid + 1;
} else {
high = mid - 1;
}
}