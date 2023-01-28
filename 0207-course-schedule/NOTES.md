return false;
}
}
return true;
}
bool isCyclic(int node, vector<vector<int>>& adjList, vector<int>& visited, vector<int>& processed) {
visited[node] = 1;
bool result = false;
for (auto neighbour: adjList[node]) {
if (visited[neighbour]) {
result = true;
break;
}
if (!processed[node]) {
result |= isCyclic(neighbour, adjList, visited, processed);
}
if (result) {
break;
}
}
processed[node] = 1;
visited[node] = 0;
return result;
}
};
​
// TC: O(n + e)
// SC: O(n + e)
```