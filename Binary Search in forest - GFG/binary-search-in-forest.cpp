// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int cutTrees(int* tree, int n, int height) {
        int woodCollected = 0;
        
        for (int i = 0; i < n; i++)
            woodCollected += max(0, tree[i] - height);
            
        return woodCollected;
    }
    
    int find_height(int tree[], int n, int k)
    {
        // int result = -1;
        
        int low = 1;
        int high = *max_element(tree, tree + n);
        // cout << low << "  " << high << " " << n << endl;
        // int high = tree[0];
        // for (int i = 0; i < n; i++)
        //     high = max(high, tree[i]);
            
        // cout << low << "  " << high << " " << n << endl;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            int woodCollected = cutTrees(tree, n, mid);
            if (woodCollected == k)
                return mid;
                
            else if (woodCollected > k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return -1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        Solution ob;
        cout<< ob.find_height(tree,n,k) << endl;
    }
    return 1;
}  // } Driver Code Ends