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
public:
    int longestPalindromeSubseq(string s) {
        string r = string(s.rbegin(), s.rend());
        
        int n = s.size();
        vector<vector<int>> store(n + 1, vector<int>(n + 1, -1));
        
        return _longestCommonSubsequence(s, r, n, n, store);
    }
};