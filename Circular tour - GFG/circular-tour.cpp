//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n) {
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = p[i].petrol - p[i].distance;
        }
        
        int result = -1;
        int count = 0;
        int start = 0;
        int end = 0;
        int sum = 0;
        while (start < n) {
            sum += diff[end];
            
            count++;
            end++;
            if (end == n) {
                end = 0;
            }
            
            while (start < n && sum < 0) {
                sum -= diff[start++];
                count--;
            }
            
            if (count == n) {
                result = start;
                break;
            }
        }
        
        return result;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends