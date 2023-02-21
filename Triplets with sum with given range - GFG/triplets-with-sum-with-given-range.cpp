//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countTriplets(int Arr[], int N, int L, int R) {
        sort(Arr, Arr + N);
        
        int result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                auto l = lower_bound(Arr + j + 1, Arr + N, L - Arr[i] - Arr[j]);
                auto r = upper_bound(Arr + j + 1, Arr + N, R - Arr[i] - Arr[j]);
                
                result += r - l;
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    }
    return 0;
}
// } Driver Code Ends