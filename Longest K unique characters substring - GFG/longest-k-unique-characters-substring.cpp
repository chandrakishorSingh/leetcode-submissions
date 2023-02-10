//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        vector<int> charFreq(26);
        
        int count = 0;
        int left = 0;
        int result = -1;
        for (int right = 0; right < s.size(); right++) {
            int pos = s[right] - 'a';
            charFreq[pos]++;
            
            if (charFreq[pos] == 1) {
                count++;
            }
            
            if (count == k) {
                result = max(result, right - left + 1);
            }
            
            while (count > k) {
                pos = s[left++] - 'a';
                charFreq[pos]--;
                
                if (charFreq[pos] == 0) {
                    count--;
                }
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
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends