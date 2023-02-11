//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // priority_queue<int> maxPQ;
        priority_queue<int, vector<int>, greater<int>> minPQ;
        for (int i = 0; i < k - 1; i++) {
            minPQ.push(arr[i]);
        }
        
        vector<int> result(n, -1);
        for (int i = k - 1; i < n; i++) {
            if (minPQ.size() < k) {
                minPQ.push(arr[i]);
                result[i] = minPQ.top();
                continue;
            }
            
            if (arr[i] > minPQ.top()) {
                minPQ.pop();
                minPQ.push(arr[i]);
            }
            
            result[i] = minPQ.top();
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends