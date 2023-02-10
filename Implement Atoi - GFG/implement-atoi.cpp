//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int num = 0;
        
        int i = str[0] == '-' ? 1 : 0;
        int sign = i == 1 ? -1 : 1;
        for (; i < str.size(); i++) {
            int ch = str[i];
            
            if (ch < '0' || ch > '9') {
                return -1;
            }
            
            num *= 10;
            num += ch - '0';
        }
        
        return num * sign;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends