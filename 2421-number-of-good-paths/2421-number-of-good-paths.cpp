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
        size[a] += size[b];
    }
    
    int find(int a) {
        if (a == parent[a])
            return a;
        
        int root = find(parent[a]);
        parent[a] = root;
        
        return root;
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<pair<int, int>> nodes(n);
        for (int i = 0; i < n; i++)
            nodes[i] = {vals[i], i};
        
        sort(nodes.begin(), nodes.end());
        
        vector<vector<int>> adjList(n, vector<int>());
        for (auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        UnionFind uf(n);
        
        int result = n;
        int currentValue = -1;
        unordered_set<int> st;
        unordered_map<int, int> componentSize;
        for (auto& node: nodes) {
            if (currentValue != node.first) {
                for (auto nodeIndex: st) {
                    componentSize[uf.find(nodeIndex)]++;
                }
                
                for (auto item: componentSize) {
                    result += (item.second * (item.second - 1)) / 2;
                }
                
                st.clear();
                componentSize.clear();
                
                currentValue = node.first;
            }
            
            for (int neighbour: adjList[node.second]) {
                if (vals[neighbour] <= node.first)
                    uf.unite(neighbour, node.second);
            }
            
            st.insert(node.second);
        }
        
        for (auto nodeIndex: st) {
            componentSize[uf.find(nodeIndex)]++;
        }

        for (auto item: componentSize) {
            result += (item.second * (item.second - 1)) / 2;
        }
        
        return result;
    }
};

// TC: O((n + e)^2)
// SC: O(n + e)