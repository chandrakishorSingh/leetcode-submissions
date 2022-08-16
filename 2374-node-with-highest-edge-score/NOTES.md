Solution 1:
​
- Straight forward approach using an array for storing the edge score of each of the nodes.
​
```
class Solution {
public:
int edgeScore(vector<int>& edges) {
int n = edges.size();
vector<int64_t> nodeValues(n);
for (int i = 0; i < n; i++) {
nodeValues[edges[i]] += i;
}
int result = -1;
int64_t maxEdgeScore = INT_MIN;
for (int i = 0; i < n; i++) {
if (nodeValues[i] > maxEdgeScore) {
maxEdgeScore = nodeValues[i];
result = i;
}
}
return result;
}
};
​
// TC: O(n)
// SC: O(n)
```