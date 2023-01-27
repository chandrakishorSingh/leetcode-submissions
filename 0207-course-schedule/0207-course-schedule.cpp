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

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < numCourses; i++) {
            pq.push({ indegrees[i], i });
        }
        
        bool result = true;
        while (numCourses != 0) {
            auto top = pq.top();
            pq.pop();
            
            if (top.first != 0) {
                result = false;
                break;
            }
            
            for (auto neighbour: adjList[top.second]) {
                indegrees[neighbour]--;
                pq.push({ indegrees[neighbour], neighbour });
            }
            
            numCourses--;
        }
        
        return result;
    }
};

// TC: O(n(n + e))
// SC: O(n + e)