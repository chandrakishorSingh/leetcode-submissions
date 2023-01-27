​
// TC: O(n(n + e))
// SC: O(n + e)
```
​
Solution 2:
​
- Use topological sorting.
- I've implemented this using an array for storing the indegrees of every node. The idea is to select a node which has an indegree of 0 and then delete it along with its associated outgoing edges. This will decrement the indegree of all adjacent nodes by 1.
- This process should be continued until every node's indegree becomes zero. If at any point in time the node with the least indegree have indegree > 0 then it means no topological order exists and hence there is a cycle.
- The node with the current minimum indegree can be find out using a heap. Observe that initially the heap will contain n elements. And after each iteration one element or node will be deleted and `outdegree(node)` number of new elements will be added into the heap. Hence, the heap will never have more than `n + e` number of elements in it.
- Also, the "twin" nodes will never be poped before the "correct" nodes because the indegree of "twin" nodes will never decrease while that of "correct" nodes will decrease as the algorithm proceeds.
​
```
class Solution {
public:
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
vector<int> indegrees(numCourses);
vector<vector<int>> adjList(numCourses);
for (auto& prerequisite: prerequisites) {
int u = prerequisite[0];
int v = prerequisite[1];
adjList[v].push_back(u);
indegrees[u]++;
}
​
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
for (int i = 0; i < numCourses; i++) {
pq.push({ indegrees[i], i });
}
bool result = true;
while (numCourses != 0) {