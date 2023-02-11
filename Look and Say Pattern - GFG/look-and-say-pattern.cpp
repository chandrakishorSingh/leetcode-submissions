//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        if (n == 1) {
            return "1";
        }
        
        string previous = lookandsay(n - 1);
        string result = "";
        int count = 1;
        char digit = previous[0];
        for (int i = 1; i < previous.size(); i++) {
            if (digit != previous[i]) {
                result.append(to_string(count));
                result.push_back(digit);
                
                digit = previous[i];
                count = 1;
            } else {
                count++;
            }
        }
        
        result.append(to_string(count));
        result.push_back(digit);
        
        return result;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends