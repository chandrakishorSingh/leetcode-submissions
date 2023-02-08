//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        vector<int> patternCharFreq(26);
        for (auto ch: p) {
            patternCharFreq[ch - 'a']++;
        }
        
        int charsSeen = 0;
        int minLength = INT_MAX;
        int start = -1;
        int end = -1;
        int left = 0;
        vector<int> windowCharFreq(26);
        for (int right = 0; right < s.size(); right++) {
            int pos = s[right] - 'a';
            windowCharFreq[pos]++;
            
            if (windowCharFreq[pos] <= patternCharFreq[pos]) {
                charsSeen++;
            }
            
            while (charsSeen == p.size()) {
                if (minLength > (right - left + 1)) {
                    minLength = right - left + 1;
                    start = left;
                    end = right;
                }
                
                
                pos = s[left++] - 'a';
                windowCharFreq[pos]--;
                charsSeen -= windowCharFreq[pos] < patternCharFreq[pos] ? 1 : 0;
            }
        }
        
        return start == -1 ? "-1" : s.substr(start, minLength);
    }
};

// zoomlazapzo
// oza

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends