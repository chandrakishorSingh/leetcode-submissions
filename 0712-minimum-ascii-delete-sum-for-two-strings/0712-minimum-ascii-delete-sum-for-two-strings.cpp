class Solution {
private:
    int solve(string& s1, string& s2, int n1, int n2, vector<vector<int>>& store) {
        if (n1 == 0 && n2 == 0) {
            return 0;
        }
        
        if (store[n1][n2] != -1) {
            return store[n1][n2];
        }
        
        if (n1 == 0) {
            store[n1][n2] = (int)s2[n2 - 1] + solve(s1, s2, n1, n2 - 1, store);
            return store[n1][n2];
        }
        
        if (n2 == 0) {
            store[n1][n2] = (int)s1[n1 - 1] + solve(s1, s2, n1 - 1, n2, store);
            return store[n1][n2];
        }
        
        if (s1[n1 - 1] == s2[n2 - 1]) {
            store[n1][n2] = solve(s1, s2, n1 - 1, n2 - 1, store);
        } else {
            store[n1][n2] = min(
                (int)s1[n1 - 1] + solve(s1, s2, n1 - 1, n2, store),
                (int)s2[n2 - 1] + solve(s1, s2, n1, n2 - 1, store)
            );
        }
        
        return store[n1][n2];
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        vector<vector<int>> store(n1 + 1, vector<int>(n2 + 1, -1));
        
        return solve(s1, s2, n1, n2, store);
    }
};