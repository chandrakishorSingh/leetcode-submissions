//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        int R = hospital.size();
        int C = hospital[0].size();
        
        vector<vector<int>> infectionTime(R, vector<int>(C, -1));
        queue<pair<int, int>> que;
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (hospital[i][j] == 0) {
                    infectionTime[i][j] = INT_MAX;
                } else if (hospital[i][j] == 2) {
                    infectionTime[i][j] = 0;
                    que.push({i, j});
                }
            }
        }
        
        while (!que.empty()) {
            auto cell = que.front();
            que.pop();
            
            int row = cell.first;
            int col = cell.second;
            vector<int> dx = {0, 1, 0, -1};
            vector<int> dy = {1, 0, -1, 0};
            
            // cout << "at cell " << row << " " << col << endl;
            
            for (int i = 0; i < dx.size(); i++) {
                for (int j = 0; j < dy.size(); j++) {
                    int newRow = row + dx[i];
                    int newCol = col + dy[i];
                    
                    if (newRow < 0 || newRow >= R || newCol < 0 || newCol >= C || infectionTime[newRow][newCol] != -1) {
                        continue;
                    }
                    
                    infectionTime[newRow][newCol] = infectionTime[row][col] + 1;
                    // cout << newRow << " " << newCol << " " << infectionTime[newRow][newCol] << endl;
                    que.push({newRow, newCol});
                }
            }
        }
        
        // for (auto& row: infectionTime) {
        //     for (auto col: row) {
        //         cout << col << " ";
        //     }
        //     cout << endl;
        // }
        
        int result = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (hospital[i][j] == 1 && infectionTime[i][j] == -1) {
                    return -1;
                }
                
                result = max(result, infectionTime[i][j] == INT_MAX ? result : infectionTime[i][j]);
            }
        }
        
        return result;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends