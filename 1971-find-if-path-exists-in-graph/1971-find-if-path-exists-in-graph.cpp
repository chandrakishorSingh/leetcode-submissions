class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visited(n);
        
        vector<vector<int>> adjList(n, vector<int>());
        
        for (auto& edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        return dfs(source, destination, visited, adjList);
    }
    
    bool dfs(int source, int destination, vector<int>& visited, vector<vector<int>>& adjList) {
        if (source == destination)
            return true;
        
        visited[source] = 1;
        
        bool result = false;
        
        for (auto& neighbour: adjList[source]) {
            if (!visited[neighbour]) {
                result |= dfs(neighbour, destination, visited, adjList);
            }
        }
        
        return result;
    }
};