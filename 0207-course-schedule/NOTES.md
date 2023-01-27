Solution 1(Brute-Force TLE):
​
- Just apply dfs on every node in the graph and see whether a cycle is detected or not.
- Need to apply dfs `n` times.
​
```
class Solution {
public:
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
vector<vector<int>> adjList(numCourses, vector<int>());
for (auto prerequisites: prerequisites) {
int u = prerequisites[0];
int v = prerequisites[1];
adjList[v].push_back(u);
}
vector<int> visited(numCourses);
for (int i = 0; i < numCourses; i++) {
if (isCyclePresent(i, adjList, visited))
return false;
}
return true;
}