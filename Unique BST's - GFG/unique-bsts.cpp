//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int mod = 1e9 + 7;
    vector<int64_t> dp;
    
    //Function to return the total number of possible unique BST. 
    int numTrees(int N) 
    {
        dp.resize(N + 1, -1);
        
        return numTrees(N, dp);
    }
    
    int64_t numTrees(int n, vector<int64_t>& dp) {
        if (n == 0)
            return 1;
            
        if (dp[n] != -1)
            return dp[n];
        
        int64_t result = 0;    
        for (int i = 1; i <= n; i++) {
            result = (result + ((numTrees(i - 1, dp) * numTrees(n - i, dp)) % mod)) % mod;
        }
        
        dp[n] = result;
        
        return dp[n];
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	
// } Driver Code Ends