class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for (auto& prerequisite: prerequisites) {
            int u = prerequisite[0];
            int v = prerequisite[1];
            
            adjList[v].push_back(u);
        }
        
        vector<int> processed(numCourses);
        vector<int> visited(numCourses);
        for (int i = 0; i < numCourses; i++) {
            if (!processed[i] && isCyclic(i, adjList, visited, processed)) {
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

// TC: O(n + e)
// SC: O(n + e)