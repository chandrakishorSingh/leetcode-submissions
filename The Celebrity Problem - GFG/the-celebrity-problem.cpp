//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution 
{
    public:
    int celebrity(vector<vector<int>>& M, int n) {
        int result = -1;
        
        for (int i = 0; i < n; i++) {
            if (isRowZero(i, M) && isColumnOne(i, M)) {
                result = i;
                break;
            }
        }
        
        return result;
    }
    
    bool isRowZero(int row, vector<vector<int>>& M) {
        bool flag = true;
        for (int i = 0; i < M.size(); i++) {
            if (M[row][i] == 1) {
                flag = false;
                break;
            }
        }
        
        return flag;
    }
    
    bool isColumnOne(int col, vector<vector<int>>& M) {
        bool flag = true;
        for (int i = 0; i < M.size(); i++) {
            if (col == i) {
                continue;
            }
            
            if (M[i][col] == 0) {
                flag = false;
                break;
            }
        }
        
        return flag;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends