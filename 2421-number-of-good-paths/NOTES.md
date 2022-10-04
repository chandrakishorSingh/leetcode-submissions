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
​
Solution 2:
​
- Use Union-Find.
- Process the nodes in increasing order of their values. For every node, add all the edges in the UF object that connects it to nodes having equal or less value than its own.
- Then we just need to find all components that contain at least one node having value equal to that of current one. If in a component, there are `m` such nodes then all of them can be used to make a total of `( m * (m - 1) ) / 2` pairs. And it's easy to see why the path that connects them will not have any node with value greater than the value of end nodes.
- Although implementation was quite hard and "not elegant"(at least it's the case with my implementation). For a given value of node, I can only count the pairs(that these nodes will make) after I've processed all of the nodes with that value as the component id(representative element of UF components) can change after adding an edge. Hence, I'm checking the component ids only after all of the nodes with the same values have been processed.
​
```
class UnionFind {
private:
vector<int> parent;
vector<int> size;
public:
UnionFind(int n) {
parent.resize(n);
for (int i = 0; i < n; i++)
parent[i] = i;
size.resize(n, 0);
}
void unite(int a, int b) {
a = find(a);
b = find(b);
if (a == b)
return;
if (size[a] < size[b])
swap(a, b);
parent[b] = a;