//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int _countPartitions(int n, int targetSum, int mod, vector<int>& arr, vector<vector<int>>& store) {
    if (n == 0) {
        return targetSum == 0 ? 1 : 0;
    }

    if (store[n][targetSum] != -1) {
        return store[n][targetSum];
    }

    int option1 = 0;
    if (arr[n - 1] <= targetSum) {
        option1 = _countPartitions(n - 1, targetSum - arr[n - 1], mod, arr, store);
    }

    int option2 = _countPartitions(n - 1, targetSum, mod, arr, store);

    store[n][targetSum] = (option1 + option2) % mod;

    return store[n][targetSum];
}
  
    int countPartitions(int n, int d, vector<int>& arr) {
            int sum = accumulate(arr.begin(), arr.end(), 0);

    if ((sum + d) % 2 == 1 || d > sum) {
        return 0;
    }

    int mod = 1e9 + 7;
    vector<vector<int>> store(n + 1, vector<int>(sum + 1, -1));

    return _countPartitions(n, (sum + d) / 2, mod, arr, store);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends