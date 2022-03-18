// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

 // } Driver Code Ends
class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        map<int, int> freq;
        for (int i = 0; i < arr.size(); i++) {
            // if (arr)
            freq[arr[i]]++;
            arr[i] = 0;
            
        }
            // freq[num]++;
            
        for (auto it = freq.begin(); it != freq.end(); it++) {
            if (it->first <= N)
                arr[it->first - 1] = it->second;
        }
    }
};


// { Driver Code Starts.

int main() 
{ 
	long long t;
	
	//testcases
	cin >> t;
	
	while(t--){
	    
	    int N, P;
	    //size of array
	    cin >> N; 
	    
	    vector<int> arr(N);
	    
	    //adding elements to the vector
	    for(int i = 0; i < N ; i++){
	        cin >> arr[i]; 
	    }
        cin >> P;
        Solution ob;
        //calling frequncycount() function
		ob.frequencyCount(arr, N, P); 
		
		//printing array elements
	    for (int i = 0; i < N ; i++) 
			cout << arr[i] << " ";
	    cout << endl;
	}	
	return 0; 
}




  // } Driver Code Ends