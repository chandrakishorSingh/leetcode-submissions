//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            int octetSeen = 0;
            int start = 0;
            int n = s.size();
            for (int i = 0; i < n; i++) {
                if (s[i] == '.') {
                    if (isOctet(s, start, i - 1)) {
                        octetSeen++;
                        start = i + 1;
                        continue;
                    } else {
                        // cout << "1" ;
                        return 0;
                    }
                }
                
                if (s[i] < '0' || s[i] > '9') {
                    // cout << "2" ;
                    return 0;
                }
            }
            
            if (!isOctet(s, start, n - 1)) {
                return 0;
            } else {
                octetSeen++;
            }
            
            return octetSeen == 4;
        }
        
        bool isOctet(string& s, int start, int end) {
            if (end < start) {
                // cout << "4 " << start << " " << end << endl;
                return false;
            }
                
            int length = end - start + 1;
            stringstream ss(s.substr(start, length));
            
            int num = INT_MAX;
            ss >> num;
            
            if (num > 255 || (s[start] == '0' && length > 1)) {
                // cout << "3" ;
                return false;
            }
            
            return true;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends