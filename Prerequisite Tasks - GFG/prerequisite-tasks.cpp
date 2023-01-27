//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<int> indegrees(numCourses);
        vector<vector<int>> adjList(numCourses);
        
        for (auto& prerequisite: prerequisites) {
            int u = prerequisite.first;
            int v = prerequisite.second;
            
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

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends