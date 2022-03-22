// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    void next(int& x1, int& y1, int& x2, int& y2, int n, int m) {
        if (x1 != 0) {
            x1--;
        } else {
            y1++;
        }
        
        if (y2 == m - 1) {
            x2--;
        } else {
            y2++;
        }
    }
  
    void diagonalSort(vector<vector<int> >& matrix, int n, int m) {
        int x1 = n - 1;
        int y1 = 0;
        
        int x2 = n - 1;
        int y2 = 0;
        
        bool flag = false;
        
        while (x1 != 0 || y1 != m - 1) {
        //   cout << x1 << ' ' << y1 << ": " << x2 << " " << y2 << endl;
            if (x1 == 0 && y1 == 0) {
                next(x1, y1, x2, y2, n, m);
                continue;
            }
             
            
            vector<int> arr;
            for (int a = x1, b = y1, j = 0; j <= min(x2 - x1, y2 - y1); a++, b++, j++) {
                arr.push_back(matrix[a][b]);
            }
            
            sort(arr.begin(), arr.end());
    
        //   for (auto n: arr) {
        //     cout << n << ' ';
        //   }
        //   cout << '\n';
            
            if (x1 == 0)
                flag = true;
            
            if (flag) {
                reverse(arr.begin(), arr.end());
            }
            
            for (int a = x1, b = y1, i = 0; i < arr.size(); a++, b++, i++) {
                matrix[a][b] = arr[i];
            }
            
            
            next(x1, y1, x2, y2, n, m);
        }
    }
        
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;

        int inputline2[n*m];
        for (int i = 0; i < n*m; ++i)
            cin>> inputline2[i];
        vector<vector<int> > matrix( n , vector<int> (m, 0));

        for(int i=0; i<n; i++) {
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = inputline2[i * m + j]; 
            }
        }
        
        Solution ob;
        ob.diagonalSort(matrix, n, m);

        // print the modified matrix
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < m; j++) { 
                cout << matrix[i][j] << " "; 
            } 
            cout << endl; 
        }    
    }
    return 0;
}

  // } Driver Code Ends