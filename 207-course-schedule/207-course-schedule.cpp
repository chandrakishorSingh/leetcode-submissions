class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses, vector<int>());
        vector<int> indegree(numCourses);

        for (auto prerequisite: prerequisites) {
            int u = prerequisite[0];
            int v = prerequisite[1];
            
            adjList[v].push_back(u);
            indegree[u]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < numCourses; i++)
            pq.push({ indegree[i], i });
        
        bool result = true;
        while (!pq.empty()) {
            auto top = pq.top();    pq.pop();
            
            if (indegree[top.second] < 0)
                continue;
            
            if (top.first != 0) {
                result = false;
                break;
            }
            
            for (auto neighbour: adjList[top.second]) {
                if (indegree[neighbour] > 0) {
                    indegree[neighbour]--;
                    pq.push({ indegree[neighbour], neighbour });
                }
            }
            
            indegree[top.second] = -1;
        }
        
        return result;
    }
};

// TC: O(n(n + e))
// SC: O(n + e)