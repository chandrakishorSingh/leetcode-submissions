class Solution {
private:
    int _longestCommonSubsequence(string& text1, string& text2, int n1, int n2, vector<vector<int>>& store) {
        if (n1 == 0 || n2 == 0) {
            return 0;
        }

        if (store[n1][n2] != -1) {
            return store[n1][n2];
        }

        int result = -1;
        if (text1[n1 - 1] == text2[n2 - 1]) {
            result = 1 + _longestCommonSubsequence(text1, text2, n1 - 1, n2 - 1, store);
        } else {
            result = max(
                _longestCommonSubsequence(text1, text2, n1 - 1, n2, store),
                _longestCommonSubsequence(text1, text2, n1, n2 - 1, store)
            );
        }


        store[n1][n2] = result;

        return store[n1][n2];
    }

    int _lcs(string& s, string& r) {
        int n1 = s.size();
        int n2 = r.size();
        vector<vector<int>> store(n1 + 1, vector<int>(n2 + 1, -1));
        
        return _longestCommonSubsequence(s, r, n1, n2, store);
    }
    
public:
    int minInsertions(string s) {
        string r = string(s.rbegin(), s.rend());
        
        return s.size() - _lcs(s, r);
    }
};