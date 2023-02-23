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
    	vector<pair<int, int>> intervals(n);
    	for (int i = 0; i < n; i++) {
    	    intervals[i] = {arr[i], dep[i]};
    	}
    	
    	sort(intervals.begin(), intervals.end());
    	
    	priority_queue<int, vector<int>, greater<int>> pq;
    	int result = 0;
    	for (int i = 0; i < n; i++) {
    	    while (!pq.empty() && pq.top() < intervals[i].first) {
    	        pq.pop();
    	    }
    	    
    	    pq.push(intervals[i].second);
    	    
    	    result = max(result, (int)pq.size());
    	}
    	
    	return result;
    }
    
    bool isIntersects(pair<int, int>& interval1, pair<int, int>& interval2) {
        return interval1.second >= interval2.first;
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