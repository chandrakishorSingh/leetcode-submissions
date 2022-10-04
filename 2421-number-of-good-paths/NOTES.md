Solution 1(Brute-Force, TLE):
​
- Observations
- In a tree, there is exactly one path that connects any two given nodes.
- For every node of the tree, just go to all other nodes and while doing so, evaluate whether this path is a "valid" path or not i.e., whether the value of all nodes lies between the value of the end nodes.
- So, we have to do a DFS for every node of the tree.
- One DFS will require O(n + e) time complexity. And the storage space of adjacency list and recursion stack space will require O(n + e) space complexity.
- Note that we don't need a "visited" array here to keep track of nodes that have been visited so far during a DFS search because there is no cycle in a tree. So, there is no possibility that a path of DFS search will reach to the same node.
​
```
class Solution {
public:
int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
int n = vals.size();
vector<vector<int>> adjList(n, vector<int>());
for (auto& edge: edges) {
int u = edge[0];
int v = edge[1];
adjList[u].push_back(v);
adjList[v].push_back(u);
}
int count = 0;
for (int i = 0; i < n; i++) {
count += dfs(i, -1, adjList, vals, vals[i]);
}
int result = n + (count / 2);
return result;
}
int dfs(int currentNode, int parentNode, vector<vector<int>>& adjList, vector<int>& vals, int nodeValue) {
int count = 0;
if (vals[currentNode] == nodeValue && parentNode != -1) {
count = 1;
}
for (auto neighbour: adjList[currentNode]) {
if (neighbour != parentNode && vals[neighbour] <= nodeValue) {
count += dfs(neighbour, currentNode, adjList, vals, nodeValue);
}
}
return count;
}
};
​
// TC: O((n + e)^2)
// SC: O(n + e)
```