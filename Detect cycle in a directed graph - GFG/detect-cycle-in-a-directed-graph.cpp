//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adjList[]) {
        vector<int> indegrees(V);
        
        for (int i = 0; i < V; i++) {
            for (auto neighbour: adjList[i]) {
                indegrees[neighbour]++;
            }
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < V; i++) {
            pq.push({ indegrees[i], i });
        }
        
        bool result = false;
        while (V != 0) {
            auto top = pq.top();
            pq.pop();
            
            if (top.first != 0) {
                result = true;
                break;
            }
            
            for (auto neighbour: adjList[top.second]) {
                indegrees[neighbour]--;
                pq.push({ indegrees[neighbour], neighbour });
            }
            
            V--;
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends