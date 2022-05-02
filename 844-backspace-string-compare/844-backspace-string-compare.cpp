class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        
        while (i >= 0 || j >= 0) {
            i = nextPosition(s, i);
            j = nextPosition(t, j);

            if (i == -1 || j == -1)
                break;
            
            if (s[i] != t[j])
                return false;
            
            i--;
            j--;
        }
        
        return i == -1 && j == -1;
    }
    
    int nextPosition(string& s, int i) {
        int count = 0;
        while (i >= 0) {
            if (s[i] == '#')
                count++;
            else if (count != 0)
                count--;
            else
                break;
            
            i--;
        }
        
        return i;
    }
};
// TC: O(len(s) + len(t))
// SC: O(1)