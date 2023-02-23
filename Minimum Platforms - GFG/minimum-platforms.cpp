//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	vector<int> prefixSum(2361);
    	
    	for (int i = 0; i < n; i++) {
    	    int arrivalTime = arr[i];
    	    int departureTime = dep[i];
    	    
    	    prefixSum[arrivalTime]++;
    	    prefixSum[departureTime + 1]--;
    	}
    	
    	int result = prefixSum[0];
    	for (int i = 1; i < prefixSum.size() - 1; i++) {
    	    prefixSum[i] += prefixSum[i - 1];
    	    result = max(result, prefixSum[i]);
    	}
    	
    	return result;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends