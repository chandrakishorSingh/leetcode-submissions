//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int countLessThan(int* arr, int n, int value) {
      int result = 0;
      for (int i = 0; i < n - 2; i++) {
          int left = i + 1;
          int right = n - 1;
          while (left != right) {
              int sum = arr[i] + arr[left] + arr[right];
              
              if (sum <= value) {
                  result += right - left;
                  left++;
              } else {
                  right--;
              }
          }
      }
      
      return result;
  }
  
  
    int countTriplets(int Arr[], int N, int L, int R) {
        sort(Arr, Arr + N);
        
        return countLessThan(Arr, N, R) - countLessThan(Arr, N, L - 1);
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