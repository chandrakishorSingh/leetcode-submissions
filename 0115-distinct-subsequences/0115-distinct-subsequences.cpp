class Solution {
private:
    int solve(int n1, int n2, string& s, string& t, vector<vector<int>>& store) {
        if (n1 == 0 && n2 == 0) {
            return 1;
        }
        
        if (n1 == 0 && n2 != 0) {
            return 0;
        }
        
        if (n1 != 0 && n2 == 0) {
            return 1;
        }
        
        if (store[n1][n2] != -1) {
            return store[n1][n2];
        }
        
        if (s[n1 - 1] == t[n2 - 1]) {
            store[n1][n2] = solve(n1 - 1, n2 - 1, s, t, store) + solve(n1 - 1, n2, s, t, store);
        } else {
            store[n1][n2] = solve(n1 - 1, n2, s, t, store);
        }
        
        // cout << "n1 = " << n1 << " n2 = " << n2 << " -> " << store[n1][n2] << endl;
        
        return store[n1][n2];
    }

public:
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        
        vector<vector<int>> store(n1 + 1, vector<int>(n2 + 1, -1));
        
        return solve(n1, n2, s, t, store);
    }
};