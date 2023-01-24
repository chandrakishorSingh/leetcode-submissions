//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        stack<int> st;
        
        int prev = INT_MIN;
        for (int i = 0; i < N; i++) {
            if (arr[i] < prev)
                return false;
                
            while (!st.empty() && st.top() < arr[i]) {
                prev = st.top();
                st.pop();
            }
            
            st.push(arr[i]);
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends