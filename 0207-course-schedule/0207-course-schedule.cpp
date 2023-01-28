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
        
        queue<int> que;
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                que.push(i);
            }
        }
        
        while (numCourses != 0 && !que.empty()) {
            auto node = que.front();
            que.pop();
            
            for (auto neighbour: adjList[node]) {
                indegrees[neighbour]--;
                
                if (indegrees[neighbour] == 0) {
                    que.push(neighbour);
                }
            }
            
            numCourses--;
        }
        
        return numCourses == 0;
    }
};

// TC: O(n * log(n + e))
// SC: O(n + e)